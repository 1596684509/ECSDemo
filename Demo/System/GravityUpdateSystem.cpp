#include "GravityUpdateSystem.h"

void GravityUpdateSystem::onUpdate(World* world, int delta) {

    std::vector<ArcheType*> arches = world->getArcheType<Velocity, Position, Gravity>();

    for (auto& arche : arches) {

        std::vector<Velocity*>velocitys = arche->getComponts<Velocity>();
        std::vector<Position*>positions = arche->getComponts<Position>();
        std::vector<Gravity*>gravitys = arche->getComponts<Gravity>();

        for (int i = 0; i < arche->getEntityCount(); ++i) {

            Velocity* velocity = velocitys[i];
            Gravity* gravity = gravitys[i];
            Position* position = positions[i];

            if (gravity->canGravity && position->y < WINDOW_HEIGHT - 200) {

                velocity->y = gravity->gravity * delta;

            }
            else {
            
                velocity->y = 0;

            }

        }

    }

}
