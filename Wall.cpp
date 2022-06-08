
#include "Wall.h"

AWall::AWall()
	:AActor() 
{
	R = 0;
	G = 255;
	B = 0;
	LoadBMP("Data/wall.bmp");
}

AWall::AWall(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder)
	: AActor(NewX, NewY, NewShape, bNewCollision, NewSortOrder) //만들 때부xj 잡아놓고 만든다.
{
	R = 0;
	G = 255;
	B = 0;
	LoadBMP("Data/wall.bmp");

}

AWall::~AWall()
{
}

