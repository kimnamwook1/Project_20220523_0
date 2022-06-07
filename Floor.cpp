#include "Floor.h"

AFloor::AFloor()
	:AActor()
{
}

AFloor::AFloor(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder)
{
	AActor::AActor(NewX, NewY, NewShape, bNewCollision, NewSortOrder);
}

AFloor::~AFloor()
{
}
