#pragma once
#include "Actor.h"

//�Է��� ó���Ѵ�. �Լ� �� ������ ȣ�����ִ� ���� �̺�Ʈ��� ��.
class APlayer : public AActor
{
public:
	APlayer();
	APlayer(int NewX, int NewY, char NewShape, bool bNewCollision = false, int NewSortOrder = 5);
	virtual ~APlayer();

	virtual void Tick() override;

	bool IsGoal();
};

