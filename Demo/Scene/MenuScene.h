#pragma once
#include "Scene.h"

#include "../Common/SceneManager.h"

class MenuScene : public Scene {

public:
	void init() override;
	void onUpdata(int delta) override;
	void onInput(GLFWwindow* window, int key, int scancode, int action, int mods) override;
	void onDraw() override;
	void onExit() override;

};