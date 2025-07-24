#include "GravityUpdateSystem.h"

void GravityUpdateSystem::onUpdate(World* world, int delta) {

    std::vector<ArcheType*> arches = world->getArcheType<Position, Gravity>();

    for (auto& arche : arches) {

        std::vector<Position*>positions = arche->getComponts<Position>();
        std::vector<Gravity*>gravitys = arche->getComponts<Gravity>();

        for (int i = 0; i < arche->getEntityCount(); ++i) {

            Position* position = positions[i];
            Gravity* gravity = gravitys[i];

            if (gravity->canGravity && position->y < WINDOW_HEIGHT - 200) {

                position->y += gravity->gravity * delta;

            }

        }

    }

}