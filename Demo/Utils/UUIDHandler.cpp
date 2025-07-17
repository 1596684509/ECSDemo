#include "UUIDHandler.h"

int UUIDHandler::uuid = 0;

int UUIDHandler::createUUID() {
	return ++uuid;
}