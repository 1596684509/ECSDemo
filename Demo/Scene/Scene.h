#pragma once

#include "../Common/World.h"

class Scene {

public:
	//场景初始化
	virtual void init() = 0;
	//每帧更新
	virtual void onUpdata(int delta) = 0;
	//输出事件
	virtual void onInput(GLFWwindow* window, int key, int scancode, int action, int mods) = 0;
	//绘制
	virtual void onDraw() = 0;
	//场景消除
	virtual void onExit() = 0;

protected:
	World* world;

};