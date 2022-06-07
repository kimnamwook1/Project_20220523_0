#include "Monster.h"

AMonster::AMonster()
	: AActor()
{
}

AMonster::AMonster(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder)
	: AActor(NewX, NewY, NewShape, bNewCollision, NewSortOrder)
{
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
}
