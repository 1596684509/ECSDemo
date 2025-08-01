#include "UUIDHandler.h"

int UUIDHandler::uuid = 2;

int UUIDHandler::createUUID() {
	return ++uuid;
}