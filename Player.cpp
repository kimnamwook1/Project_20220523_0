#include "Player.h"
#include "World.h"
#include "Engine.h" // keycode 갖고 오기 위햐
#include "Goal.h"
#include "Monster.h"
#include "SDL.h"
#include <iostream>


APlayer::APlayer()
	: AActor()
{
	R = 255;
	G = 0;
	B = 255;
	ColorKey = SDL_Color{ 255, 0, 255, 0 };
	LoadBMP("Data/player.bmp");
}

APlayer::APlayer(int NewX, int NewY, char NewShape, bool bNewCollision, int NewSortOrder)
	: AActor(NewX, NewY, NewShape, bNewCollision, NewSortOrder)
{
	R = 255;
	G = 0;
	B = 255;
	ColorKey = SDL_Color{ 255, 0, 255, 0 };
	LoadBMP("Data/player.bmp");
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	ElapsedTime += GEngine->GetWorldDeltaSeconds();
	if (ElapsedTime >= ProcessTime)
	{
		SpriteIndex++;
		SpriteIndex = SpriteIndex % 5;
		ElapsedTime = 0;
	}

	switch (GEngine->MyEvent.type)
	{
	case SDL_QUIT:
		GEngine->QuitGame();
		break;
	case SDL_KEYDOWN:
		switch(GEngine->MyEvent.key.keysym.sym)
		{
		case SDLK_w:
			Y = PredictCollision(X, Y - 1) == false ? Y - 1 : Y;
			SpriteDirection = 2;
			break;
		case SDLK_s:
			Y = PredictCollision(X, Y + 1) == false ? Y + 1 : Y;
			SpriteDirection = 3;
			break;
		case SDLK_a :
			X = PredictCollision(X - 1, Y) == false ? X - 1 : X;
			SpriteDirection = 0;

			break;
		case SDLK_d :
			X = PredictCollision(X + 1, Y) == false ? X + 1 : X;
			SpriteDirection = 1;
			break;
		}
	}

	if (IsGoal())
	{
		GEngine->QuitGame();
	}
}

void APlayer::Render()
{
	if (Texture == nullptr)
	{
		SDL_SetRenderDrawColor(GEngine->MyRenderer, R, G, B, A);
		SDL_RenderFillRect(GEngine->MyRenderer, new SDL_Rect{ X * Size, Y * Size, Size, Size });
	}
	else
	{
		int SpriteWidth = Image->w / 5;
		int SpriteHeight = Image->h / 5;

		SDL_Rect SourceRect{ SpriteIndex * SpriteWidth, SpriteDirection * SpriteHeight, SpriteWidth, SpriteHeight };

		SDL_RenderCopy(GEngine->MyRenderer, Texture, &SourceRect, new SDL_Rect{ X * Size, Y * Size, Size, Size });
	}
}

bool APlayer::IsGoal()
{
	for (auto Actor : GEngine->GetWorld()->MyActors)
	{
		
		if (Actor->X == X && Actor->Y == Y)
		{
			AGoal* Goal = dynamic_cast<AGoal*>(Actor); //dynamic cast는 무조건 포인터로 사용해야 한다.
			if(Goal != nullptr)
			{
				return true;
			}	
		}
		
	}
	return false;
}
