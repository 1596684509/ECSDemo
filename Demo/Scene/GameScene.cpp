#include "GameScene.h"

void GameScene::init() {
	world = new World();
	initEntity();
	initSystem();
}
void GameScene::onUpdata(int delta) {

	world->getEventBus()->commit();
	world->onUpdate(delta);

}
void GameScene::onInput(GLFWwindow* window, int key, int scancode, int action, int mods) {

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
	
		SceneManager::getInstance()->switchTo(SceneManager::Type::MenuScene, true);

	}
	else {
	
		world->onInput(window, key, scancode, action, mods);
	
	}

	
}
void GameScene::onDraw() {

	world->onDraw();

}
void GameScene::onExit() {

	if (world) {

		delete world;
		world = nullptr;

	}

}

void GameScene::initEntity() {

	Entity* entity1 = new Entity();
	world->addComponent(entity1, new Position(300, 300));
	world->addComponent(entity1, new MoveState());
	InputKey* inputkey1 = InputKey::InputKeyBuilder()
		.setMoveDown(GLFW_KEY_S)
		.setMoveLeft(GLFW_KEY_A)
		.setMoveRight(GLFW_KEY_D)
		.setRun(GLFW_KEY_SPACE)
		.setJump(GLFW_KEY_W)
		.build();

	world->addComponent(entity1, inputkey1);
	world->addComponent(entity1, new Velocity(0.5f, 0));
	world->addComponent(entity1, new Gravity(1.6e-3f));
	world->addComponent(entity1, new Jump(3, -0.5f));

	world->commitComponent();

}

void GameScene::initSystem() {

	world->getEventBus()->registerEventListener<InputEvent>(new MoveInputListener(world));
	world->getEventBus()->registerEventListener<JumpEvent>(new JumpListener(world));

	world->registerUpdateSystem(new MoveUpdateSystem());
	world->registerUpdateSystem(new GravityUpdateSystem());
	world->registerDrawSystem(new CharacterDrawSystem());

}