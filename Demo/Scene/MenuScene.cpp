#include "MenuScene.h"

void MenuScene::init(){}
void MenuScene::onUpdata(int delta){}
void MenuScene::onInput(GLFWwindow* window, int key, int scancode, int action, int mods){

	if (action == GLFW_PRESS && key == GLFW_KEY_SPACE) {
	
		SceneManager::getInstance()->removeScene(SceneManager::Type::GameScene);

	}

}
void MenuScene::onDraw(){}
void MenuScene::onExit(){

	if (world) {
	
		delete world;
		world = nullptr;

	}

}