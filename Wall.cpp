
#include "Wall.h"

AWall::AWall()
	:AActor() 
{
}

AWall::AWall(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder)
	: AActor(NewX, NewY, NewShape, bNewCollision, NewSortOrder) //만들 때부xj 잡아놓고 만든다.
{
}

AWall::~AWall()
{
}

