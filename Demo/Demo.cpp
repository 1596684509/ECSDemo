
#include "Demo.h"

using namespace std;

SceneManager* sceneManager = SceneManager::getInstance();
bool isRunning = true;

void onInput(GLFWwindow* window, int key, int scancode, int action, int mods) {

	sceneManager->getNowScene()->onInput(window, key, scancode, action, mods);

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

	glfwSetKeyCallback(window, onInput);

	DWORD64 start = GetTickCount64();

	while (!glfwWindowShouldClose(window) && isRunning) {

		DWORD64 loopStart = GetTickCount64();
		DWORD64 update = loopStart - start;
		start = loopStart;
		//处理IO
		glfwPollEvents();
		//更新
		sceneManager->getNowScene()->onUpdata(update);
		sceneManager->backgroundUpdata(update);
		//绘制
		glClear(GL_COLOR_BUFFER_BIT);
		sceneManager->getNowScene()->onDraw();
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
