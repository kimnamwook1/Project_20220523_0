#pragma once
//2���� �󿡼� �ڽ��� �������ϰ� �浹�ϰ� ó���Ѵ�.
class AActor
{
public:
	AActor();
	AActor(int NewX, int NewY, char NewShape, bool bNewCollision = false);
	virtual ~AActor();

	char Shape;
	int X;
	int Y;
	bool bCollision;

	virtual void Tick();
	virtual void Render();
};

