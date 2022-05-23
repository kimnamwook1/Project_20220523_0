#pragma once
#include "Actor.h"

//입력을 처리한다. 함수 중 엔진이 호출해주는 것을 이벤트라고 함.
class APlayer : public AActor
{
public:
	APlayer();
	APlayer(int NewX, int NewY, char NewShape, bool bNewCollision = false);
	virtual ~APlayer();

	virtual void Tick() override;
};

