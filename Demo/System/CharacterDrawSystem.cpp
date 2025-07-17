#include "CharacterDrawSystem.h"

void CharacterDrawSystem::onDraw(World *world) {

    std::vector<ArcheType *> archetypes =world->getArcheType<Position>();

    for (auto& archetype : archetypes) {

        std::vector<Position*> positions = archetype->getComponts<Position>();
        for (auto& position : positions) {

            glColor3f(0, 0, 0);
            glBegin(GL_TRIANGLE_FAN);
            glVertex2f(position->x, position->y);

            for (int i = 0; i < 50; ++i) {

                float angle = i * 2.0f * 3.14159f / 50;
                float dx = cos(angle) * 10;
                float dy = sin(angle) * 10;
                glVertex2f(position->x + dx, position->y + dy);

            }

            glEnd();

        }

    }

}
