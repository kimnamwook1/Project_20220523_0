
#include "Wall.h"

AWall::AWall()
	:AActor() 
{
}

AWall::AWall(int NewX, int NewY, char NewShape, bool bNewCollision)
	: AActor(NewX, NewY, NewShape, bNewCollision) //만들 때부토 잡아놓고 만든다.
{
}

AWall::~AWall()
{
}

