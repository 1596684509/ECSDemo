#include "SceneManager.h"

SceneManager::SceneManager() {

	switchTo(Type::MenuScene, false);

}

Scene* SceneManager::getNowScene() {

	return nowScene;

}

void SceneManager::switchTo(Type type, bool isActive) {

	if (nowScene) {
	
		if (isActive) {

			backgroundScene[nowSceneType] = nowScene;

		}
		else {

			inactiveSecne[nowSceneType] = nowScene;

		}

	}

	if (backgroundScene.find(type) != backgroundScene.end()) {
		nowScene = backgroundScene[type];
		backgroundScene.erase(type);
	}
	else if (inactiveSecne.find(type) != inactiveSecne.end()) {
		nowScene = inactiveSecne[type];
		inactiveSecne.erase(type);
	}
	else {
		nowScene = createScene(type);
	}

	nowSceneType = type;

}

Scene* SceneManager::createScene(Type type){

	Scene* sc = nullptr;
	switch (type) {
	
	case Type::MenuScene:
		sc = new MenuScene();
		break;
	case Type::GameScene:
		sc = new GameScene();
		break;
	}

	sc->init();
	return sc;

}

void SceneManager::removeScene(Type type) {

	if (nowScene) {
		nowScene->onExit();
		delete nowScene;
		nowScene = nullptr;
	}

	switchTo(type, false);

}

SceneManager* SceneManager::getInstance() {

	static SceneManager sceneManager;
	return &sceneManager;

}



void SceneManager::backgroundUpdata(int delta) {

	for (auto&& scene : backgroundScene) {
	
		scene.second->onUpdata(delta);

	}

}