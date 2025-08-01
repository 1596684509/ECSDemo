#pragma once

#include "Scene.h"

#include "../Common/SceneManager.h"

#include "../Component/Position.h"
#include "../Component/Velocity.h"
#include "../Component/Gravity.h"
#include "../Component/Jump.h"
#include "../Component/Camera.h"

#include "../System/CharacterDrawSystem.h"
#include "../System/MoveUpdateSystem.h"
#include "../System/GravityUpdateSystem.h"

#include "../Listener/MoveInputListener.h"
#include "../Listener/JumpListener.h"

#include "../Utils/PoolHandler.h"

class GameScene: public Scene {

public:
	void init() override;
	void onUpdata(int delta) override;
	void onInput(GLFWwindow* window, int key, int scancode, int action, int mods) override;
	void onDraw() override;
	void onExit() override;

private:
	void initEntity();
	void initSystem();

};