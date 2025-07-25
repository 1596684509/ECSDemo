#include "GravityUpdateSystem.h"

void GravityUpdateSystem::onUpdate(World* world, int delta) {

    std::vector<ArcheType*> arches = world->getArcheType<Velocity, Position, Gravity>();

    for (auto& arche : arches) {

        std::vector<Velocity*>velocitys = arche->getComponents<Velocity>();
        std::vector<Position*>positions = arche->getComponents<Position>();
        std::vector<Gravity*>gravitys = arche->getComponents<Gravity>();

        for (int i = 0; i < arche->getEntityCount(); ++i) {

            Velocity* velocity = velocitys[i];
            Gravity* gravity = gravitys[i];
            Position* position = positions[i];

            if (!gravity->canGravity) {
            
                continue;

            }

            velocity->y += gravity->gravity;

        }

    }

}
