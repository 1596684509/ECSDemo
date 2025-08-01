//
// Created by admin on 25-7-17.
//

#include "MoveUpdateSystem.h"

void MoveUpdateSystem::onUpdate(World *world, int delta) {

    std::vector<ArcheType*> arches = world->getArcheType<Position, Velocity, MoveState, Jump>();

    for (auto& arche : arches) {

        std::vector<Position*>positions = arche->getComponents<Position>();
        std::vector<Velocity*>velocitys = arche->getComponents<Velocity>();
        std::vector<MoveState*>moveStates = arche->getComponents<MoveState>();
        std::vector<Jump*>jumps = arche->getComponents<Jump>();

        for (int i = 0; i < arche->getEntityCount(); ++i) {

            Position* position = positions[i];
            Velocity* velocity = velocitys[i];
            MoveState* moveState = moveStates[i];
            Jump* jump = jumps[i];

            float speedX = velocity->x;

            if (moveState->canMove) {

                if (moveState->isRun) {
                
                    speedX *= 2;

                }

                int direction = moveState->isRight - moveState->isLeft;
                position->x += speedX * delta * direction;
                position->y += velocity->y * delta;

                position->x = std::max(0, (int)position->x);
                position->x = std::min(WORLD_WIDTH, (int)position->x);

                position->y = std::max(0, (int)position->y);
                position->y = std::min(WORLD_WIDTH, (int)position->y);

                if (position->y > GROUND_HEIGHT) {
                
                    position->y = GROUND_HEIGHT;
                    moveState->inGround = true;
                    velocity->y = 0;
                    moveState->canJump = true;
                    moveState->isJump = false;
                    jump->nowJumpCount = 0;
                }

                if (arche->getEntity(i) == Entity::getPlayer()) {
                    setCameraPosition(world, position);
                }


            }

        }

    }

}

void MoveUpdateSystem::setCameraPosition(World* world, const Position* position) {

    Camera* camera = world->getCamera();

    // 先居中跟随
    camera->x = position->x - WINDOW_WIDTH / 2;
    camera->y = position->y - WINDOW_HEIGHT / 2;

    // 再限制在地图范围内（避免越界）
    if (camera->x < 0) camera->x = 0;
    if (camera->y < 0) camera->y = 0;
    if (camera->x > WORLD_WIDTH - WINDOW_WIDTH) camera->x = WORLD_WIDTH - WINDOW_WIDTH;
    if (camera->y > WORLD_HEIGHT - WINDOW_HEIGHT) camera->y = WORLD_HEIGHT - WINDOW_HEIGHT;

}

