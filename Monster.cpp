#include "Player.h"
#include "World.h"
#include "Engine.h" // keycode 갖고 오기 위햐
#include "Goal.h"
#include "Monster.h"
#include "SDL.h"
#include "Actor.h"

AMonster::AMonster()
	: AActor()
{
	R = 0;
	G = 255;
	B = 255;
	LoadBMP("Data/slime.bmp");
}

AMonster::AMonster(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder)
	: AActor(NewX, NewY, NewShape, bNewCollision, NewSortOrder)
{
	srand((unsigned int)time(NULL));
	R = 0;
	G = 255;
	B = 255;
	LoadBMP("Data/slime.bmp");
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{


	ElapsedTimeM += GEngine->GetWorldDeltaSeconds();
	if (ElapsedTimeM >= ProcessTimeM)
	{
	
		int MonsterIndex = rand() % 4;
	

		switch (MonsterIndex)
		{
		case 0:
			Y = PredictCollision(X, Y - 1) == false ? Y - 1 : Y;
			break;
		case 1:
			Y = PredictCollision(X, Y + 1) == false ? Y + 1 : Y;
			break;
		case 2:
			X = PredictCollision(X - 1, Y) == false ? X - 1 : X;
			break;
		case 3:
			X = PredictCollision(X + 1, Y) == false ? X + 1 : X;
			break;

			
		}
		ElapsedTimeM = 0;
		
	}
	if (IsPlayer())
	{
		SDL_Log("Game Over");
		GEngine->QuitGame();
	}


}
bool AMonster::IsPlayer()
{
	for (auto Actor : GEngine->GetWorld()->MyActors)
	{

		if (Actor->X == X && Actor->Y == Y)
		{
			APlayer* Player = dynamic_cast<APlayer*>(Actor); //dynamic cast는 무조건 포인터로 사용해야 한다.
			if (Player != nullptr)
			{
				return true;
			}
		}

	}
	return false;
}