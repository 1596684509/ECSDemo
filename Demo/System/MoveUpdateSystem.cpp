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

                if (position->y > GROUND_HEIGHT) {
                
                    position->y = GROUND_HEIGHT;
                    moveState->inGround = true;
                    velocity->y = 0;
                    moveState->canJump = true;
                    moveState->isJump = false;
                    jump->nowJumpCount = 0;
                }


            }

        }

    }

}
