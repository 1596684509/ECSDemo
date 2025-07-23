#include "MoveInputListener.h"

MoveInputListener::MoveInputListener(World* world) : EventListener(world) {}

void MoveInputListener::onEvent(const InputEvent* event) {

    if (event->action == GLFW_PRESS) {
    
        onPress(event->key, event->mods);

    }
    else if (event->action == GLFW_RELEASE) {
    
        onRelease(event->key, event->mods);

    }

}

void MoveInputListener::onPress(int key, int mods) {

    std::vector<ArcheType*> archeTypes = world->getArcheType<MoveState, InputKey>();
    for (ArcheType* archeType : archeTypes) {

        std::vector<MoveState*> moves = archeType->getComponts<MoveState>();
        std::vector<InputKey*> inputKeys = archeType->getComponts<InputKey>();

        for (int i = 0; i < archeType->getEntityCount(); ++i) {

            MoveState* moveState = moves[i];
            InputKey* inputKey = inputKeys[i];

            if (key == inputKey->moveLeft) moveState->isLeft = true;
            if (key == inputKey->moveRight) moveState->isRight = true;
            if (key == inputKey->run) moveState->isRun = true;

        }

    }

}

void MoveInputListener::onRelease(int key, int mods) {

    std::vector<ArcheType*> archeTypes = world->getArcheType<MoveState, InputKey>();
    for (ArcheType* archeType : archeTypes) {

        std::vector<MoveState*> moves = archeType->getComponts<MoveState>();
        std::vector<InputKey*> inputKeys = archeType->getComponts<InputKey>();

        for (int i = 0; i < archeType->getEntityCount(); ++i) {

            MoveState* moveState = moves[i];
            InputKey* inputKey = inputKeys[i];

            if (key == inputKey->moveLeft) moveState->isLeft = false;
            if (key == inputKey->moveRight) moveState->isRight = false;
            if (key == inputKey->run) moveState->isRun = false;

        }

    }

}
