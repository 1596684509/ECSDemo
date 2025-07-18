#include "CharacterDrawSystem.h"


static unsigned int VAO = 0, VBO = 0;
static unsigned int shaderProgram = 0;
static const int segments = 50;

static bool initialized = false;

static const char* vertexShaderSrc = R"(
    #version 330 core
    layout(location = 0) in vec2 aPos;
    uniform vec2 uOffset;
    void main() {
        gl_Position = vec4(aPos + uOffset, 0.0, 1.0);
    }
)";

static const char* fragmentShaderSrc = R"(
    #version 330 core
    out vec4 FragColor;
    void main() {
        FragColor = vec4(1.0, 1.0, 1.0, 1.0);
    }
)";

static unsigned int compileShader(unsigned int type, const char* source) {
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("Shader compilation error: %s\n", infoLog);
    }
    return shader;
}

static unsigned int createProgram() {
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShaderSrc);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSrc);
    unsigned int program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        printf("Program link error: %s\n", infoLog);
    }
    glDeleteShader(vs);
    glDeleteShader(fs);
    return program;
}

void CharacterDrawSystem::onDraw(World* world) {
    if (!initialized) {
        // 生成?位??点(三角扇)
        std::vector<float> vertices;
        vertices.push_back(0.0f);
        vertices.push_back(0.0f);
        for (int i = 0; i <= segments; ++i) {
            float angle = 2.0f * 3.1415926f * i / segments;
            vertices.push_back(cos(angle) * 0.05f); 
            vertices.push_back(sin(angle) * 0.05f);
        }

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        shaderProgram = createProgram();
        initialized = true;
    }

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);

    int offsetLoc = glGetUniformLocation(shaderProgram, "uOffset");

    std::vector<ArcheType*> archetypes = world->getArcheType<Position>();

    for (auto& archetype : archetypes) {
        std::vector<Position*> positions = archetype->getComponts<Position>();
        for (auto& position : positions) {

            float ndcX = (position->x / (WINDOW_WIDTH / 2.0f)) - 1.0f;
            float ndcY = 1.0f - (position->y / (WINDOW_HEIGHT / 2.0f));
            // ?置当前?体?形偏移
            glUniform2f(offsetLoc, ndcX, ndcY);
            // ?制三角扇，?点数 = segments + 2 (?心 + segments+1点)
            glDrawArrays(GL_TRIANGLE_FAN, 0, segments + 2);
        }
    }

    glBindVertexArray(0);
    glUseProgram(0);
}
