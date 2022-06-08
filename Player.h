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
	virtual void Render() override;

	bool IsGoal();

	Uint64 ElapsedTime = 0;
	Uint64 ProcessTime = 10; // �и�������

	int SpriteIndex = 0; 
	int SpriteDirection = 0;
};

