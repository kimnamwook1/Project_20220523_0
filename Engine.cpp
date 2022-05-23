#include <iostream>
#include <fstream>

#include "Engine.h"
#include "World.h"
#include "Wall.h"
#include "Player.h"
#include "Goal.h"
#include "Floor.h"
#include "Monster.h"


Engine::Engine()
{
	Initialize();
}

Engine::~Engine()
{
	Terminate();
}

void Engine::Initialize()
{
	bRunning = true;
	Myworld = new World();
}

void Engine::Load(string MapFilename)
{
	//for (int i = 0; i <= 9; ++i)
	//{
	//	Myworld->MyActors.push_back(new AWall(i, 0, '#', true));// 마이월드에 있는 마이엑터라는 리스트에 새로운 벽으로 추가한다.
	//	Myworld->MyActors.push_back(new AWall(i, 9, '#', true));
	//}

	//for (int i = 1; i <= 8; ++i)
	//{
	//	Myworld->MyActors.push_back(new AWall(0, i, '#', true));
	//	Myworld->MyActors.push_back(new AWall(9, i, '#', true));
	//}


	//Myworld->MyActors.push_back(new APlayer(1, 1, 'P', true));
	//Myworld->MyActors.push_back(new AGoal(8, 8, 'G', true));
	ifstream MapFile(MapFilename); // 입력 파일 , 괄호 안에는 파일 이름

	int Y = 0;
	while (MapFile.peek() != EOF)//peek 이 맵을 가져오는 함수
	{
		char Buffer[1024] = { 0, };
		MapFile.getline(Buffer, 1024);

		for (size_t X = 0; X < strlen(Buffer); ++X)
		{
			char Cursor = Buffer[X];
			switch (Cursor)
			{
			case '#':
				Myworld->MyActors.push_back(new AWall(X, Y, '#', true));
				break;
			case ' ':
				Myworld->MyActors.push_back(new AFloor(X, Y, ' ', false));
				break;
			case 'P':
				Myworld->MyActors.push_back(new APlayer(X, Y, 'P', true));
				break;
			case 'G':
				Myworld->MyActors.push_back(new AGoal(X, Y, 'G', false));
				break;
			case 'M':
				Myworld->MyActors.push_back(new AMonster(X, Y, 'M', false));
				break;
			}
		}
		Y++;
	}
	MapFile.close();
}


void Engine::Run()
{
	while (bRunning) //1Frame
	{
		Myworld->Tick();
		Myworld->Render();
	}
}

void Engine::Terminate()
{
	delete Myworld;
	Myworld = nullptr;
}
