//
// Created by admin on 25-7-17.
//

#include "MoveUpdateSystem.h"

void MoveUpdateSystem::onUpdate(World *world, int delta) {

    std::vector<ArcheType*> arches = world->getArcheType<Position, Velocity, MoveState>();

    for (auto& arche : arches) {

        std::vector<Position*>positions = arche->getComponts<Position>();
        std::vector<Velocity*>velocitys = arche->getComponts<Velocity>();
        std::vector<MoveState*>moveStates = arche->getComponts<MoveState>();

        for (int i = 0; i < arche->getEntityCount(); ++i) {

            Position* position = positions[i];
            Velocity* velocity = velocitys[i];
            MoveState* moveState = moveStates[i];

            float speedX = velocity->x;

            if (moveState->canMove) {

                if (moveState->isRun) {
                
                    speedX *= 2;

                }

                int direction = moveState->isRight - moveState->isLeft;
                position->x += speedX * delta * direction;

            }

        }

    }

}
