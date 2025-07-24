//
// Created by admin on 25-7-17.
//

#include "MoveUpdateSystem.h"

void MoveUpdateSystem::onUpdate(World *world, int delta) {

    std::vector<ArcheType*> arches = world->getArcheType<Position, Velocity, MoveState>();

    for (auto& arche : arches) {

        std::vector<Position*>positions = arche->getComponents<Position>();
        std::vector<Velocity*>velocitys = arche->getComponents<Velocity>();
        std::vector<MoveState*>moveStates = arche->getComponents<MoveState>();

        for (int i = 0; i < arche->getEntityCount(); ++i) {

            Position* position = positions[i];
            Velocity* velocity = velocitys[i];
            MoveState* moveState = moveStates[i];

            float speedX = velocity->x;

            if (moveState->canMove) {

                if (moveState->isRun) {
                
                    speedX *= 2;

                }

                if (moveState->isJump && velocity->y == 0) {
                
                    moveState->isJump = false;
                    moveState->canJump = true;

                }

                int direction = moveState->isRight - moveState->isLeft;
                position->x += speedX * delta * direction;
                position->y += velocity->y;

            }

        }

    }

}
