#pragma once
#include "Actor.h"
#include "Engine.h"
class AMonster : public AActor
{
public:
		AMonster();
		virtual ~AMonster();

		AMonster(int NewX, int NewY, char NewShape, bool bNewCollision = false, int NewSortOrder = 4);

		virtual void Tick() override;

		Uint64 ElapsedTimeM = 0;
		Uint64 ProcessTimeM = 100; // 밀리세컨드

		bool IsPlayer();
};


