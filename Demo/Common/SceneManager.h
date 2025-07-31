#pragma once

#include <stack>
#include <unordered_map>

#include "../Scene/Scene.h"
#include "../Scene/MenuScene.h"
#include "../Scene/GameScene.h"

class SceneManager {

public:
	enum class Type {
		MenuScene = 0,
		GameScene
	};

public:
	//切换场景
	void switchTo(Type type, bool isActive);
	//创建场景
	Scene* createScene(Type type);
	//移除当前场景并切换场景
	void removeScene(Type type);
	SceneManager(const SceneManager& scene) = delete;
	SceneManager& operator=(const SceneManager& scene) = delete;
	Scene* getNowScene();
	static SceneManager* getInstance();
	//每帧更新
	void backgroundUpdata(int delta);


private:
	SceneManager();
	//后台场景，随程序更新
	std::unordered_map<Type, Scene*> backgroundScene;
	//非活跃场景，不随程序更新
	std::unordered_map<Type, Scene*> inactiveSecne;
	Scene* nowScene;
	Type nowSceneType;

};