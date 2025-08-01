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

	Entity* globalEntity = Entity::getGloBalEntity();
	Camera* camera = new Camera();
	camera->x = 0;
	camera->y = 0;
	camera->width = WINDOW_WIDTH;
	camera->height = WINDOW_HEIGHT;
	world->addComponent(globalEntity, camera);

	PoolHandler* poolHandler = PoolHandler::getInstance();
	MoveState* moveState = poolHandler->getObject<MoveState>();

	Velocity* velocity = poolHandler->getObject<Velocity>();
	velocity->x = 0.5;
	velocity->y = 0;

	Position* position = poolHandler->getObject<Position>();
	position->x = 0;
	position->y = 0;

	Gravity* gravity = poolHandler->getObject<Gravity>();
	gravity->gravity = 1.6e-3f;

	Jump* jump = poolHandler->getObject<Jump>();
	jump->jumpPower = -0.5f;
	jump->maxJumpCount = 3;

	InputKey* inputkey1 = InputKey::InputKeyBuilder()
		.setMoveDown(GLFW_KEY_S)
		.setMoveLeft(GLFW_KEY_A)
		.setMoveRight(GLFW_KEY_D)
		.setRun(GLFW_KEY_SPACE)
		.setJump(GLFW_KEY_W)
		.build();

	Entity* player1 = Entity::getPlayer();
	world->addComponent(player1, position);
	world->addComponent(player1, moveState);
	world->addComponent(player1, inputkey1);
	world->addComponent(player1, velocity);
	world->addComponent(player1, gravity);
	world->addComponent(player1, jump);

	world->commitComponent();

}

void GameScene::initSystem() {

	world->getEventBus()->registerEventListener<InputEvent>(new MoveInputListener(world));
	world->getEventBus()->registerEventListener<JumpEvent>(new JumpListener(world));

	world->registerUpdateSystem(new MoveUpdateSystem());
	world->registerUpdateSystem(new GravityUpdateSystem());
	world->registerDrawSystem(new CharacterDrawSystem());

}