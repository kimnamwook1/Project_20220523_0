#include "Player.h"
#include "World.h"
#include "Engine.h" // keycode ���� ���� ����
#include "Goal.h"

APlayer::APlayer()
	: AActor()
{
}

APlayer::APlayer(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder)
	: AActor(NewX, NewY, NewShape, bNewCollision, NewSortOrder)
{
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	int KeyCode = Engine::GetKeyCode();

	switch (KeyCode)
	{
	case 'w': 
		Y =PredictCollision(X, Y - 1) == false ? Y -1 : Y;
		break;
	case 's':
		Y = PredictCollision(X, Y + 1) == false ? Y + 1 : Y;
		break;
	case 'a':
		X = PredictCollision(X - 1 , Y) == false ? X - 1 : X;
		break;
	case 'd':
		X = PredictCollision(X + 1, Y) == false ? X + 1 : X;
		break;
	}

	if (IsGoal())
	{
		GEngine->QuitGame();
	}
}

bool APlayer::IsGoal()
{
	for (auto Actor : GEngine->GetWorld()->MyActors)
	{
		
		if (Actor->X == X && Actor->Y == Y)
		{
			AGoal* Goal = dynamic_cast<AGoal*>(Actor); //dynamic cast�� ������ �����ͷ� ����ؾ� �Ѵ�.
			if(Goal != nullptr)
			{
				return true;
			}
			
		}
	}
	return false;
}
