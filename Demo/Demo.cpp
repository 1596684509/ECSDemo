
#include "Demo.h"


using namespace std;

World* world = new World();
bool isRunning = true;

void onInput(GLFWwindow* window, int key, int scancode, int action, int mods) {

	world->onInput(window, key, scancode, action, mods);

}

void initEntity() {

	Entity* entity1 = new Entity();
	world->addComponent(entity1, new Position(300, 300));
	world->addComponent(entity1, new MoveState());
	InputKey* inputKey1 = new InputKey();
	inputKey1->setMoveKey(GLFW_KEY_S, GLFW_KEY_A, GLFW_KEY_D);
	inputKey1->setRun(GLFW_KEY_SPACE);
	inputKey1->setJumpKey(GLFW_KEY_W);
	world->addComponent(entity1, inputKey1);
	world->addComponent(entity1, new Velocity(0.5f, 0));
	world->addComponent(entity1, new Gravity(0.098f));
	world->addComponent(entity1, new Jump(2, -1.1f));

	world->commitComponent();

}

void initSystem() {

	world->getEventBus()->registerEvent<InputEvent>(new MoveInputListener(world));
	world->getEventBus()->registerEvent<JumpEvent>(new JumpListener(world));

	world->registerUpdateSystem(new MoveUpdateSystem());
	world->registerUpdateSystem(new GravityUpdateSystem());
	world->registerDrawSystem(new CharacterDrawSystem());

}

int main() {


	if (!glfwInit()) return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Demo", nullptr, nullptr);


	if (!window) {
		glfwTerminate();
		return - 1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return -1;
	}

	initEntity();
	initSystem();

	
	glfwSetKeyCallback(window, onInput);

	DWORD64 start = GetTickCount64();

	while (!glfwWindowShouldClose(window) && isRunning) {

		DWORD64 loopStart = GetTickCount64();
		DWORD64 update = loopStart - start;
		start = loopStart;
		//处理IO
		glfwPollEvents();
		//更新
		world->getEventBus()->commit();
		world->onUpdate(update);
		//绘制
		glClear(GL_COLOR_BUFFER_BIT);
		world->onDraw();
		glfwSwapBuffers(window);
		//限制帧数
		DWORD64 loopEnd = GetTickCount64();
		DWORD64 diff = loopEnd - loopStart;

		if (diff < 1000 / FPS) {
			Sleep(1000 / FPS - diff);
		}

	}

	glfwDestroyWindow(window);
	glfwTerminate();


}
