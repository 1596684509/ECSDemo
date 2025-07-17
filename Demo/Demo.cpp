// Demo.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "Demo.h"


using namespace std;

bool isRunning = true;

void onInput(GLFWwindow* window, int key, int scancode, int action, int mods) {



}

int main() {


	if (!glfwInit()) return -1;

	GLFWwindow* window = glfwCreateWindow(WINDOW_WEIGHT, WINDOW_HEIGHT, "Demo", nullptr, nullptr);

	if (!window) {
		glfwTerminate();
		return - 1;
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, onInput);

	while (!glfwWindowShouldClose(window) && isRunning) {
	
		//处理IO
		glfwPollEvents();
		//更新
		//绘制
		//限制帧数

	}





}
