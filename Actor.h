#pragma once
#include "ESpriteType.h"

//2차원 상에서 자신을 랜더링하고 충돌하고 처리한다.
class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY, char NewShape, bool bNewCollision = false, int NewSortOrder = 1);
	virtual ~AActor();

	ESpriteType Type;
	char Shape;
	int X;
	int Y;
	bool bCollision;
	int SortOrder;

	virtual void Tick();
	virtual void Render();

	static bool Compare(AActor* First, AActor* Second)
	{ 
		return First->SortOrder < Second->SortOrder; // 내림차순 정리하겠다.
	}

	bool PredictCollision(int PredictX, int PredictY);

};

