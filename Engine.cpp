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
	MyWorld = new World();
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
	while (MapFile.peek() != EOF)//peek==몇번쨰 줄 몇번쨰 칸인지 // EOF =end of file
	{
		char Buffer[1024] = { 0, };
		MapFile.getline(Buffer, 1024); // 한 줄을 읽어와라.

		for (size_t X = 0; X < strlen(Buffer); ++X) // 버퍼의 사이즈는 양수이기에 size_t를 사용
		{
			char Cursor = Buffer[X];
			switch (Cursor)
			{
			case '#':
				MyWorld->MyActors.push_back(new AWall(X, Y, '#', true));
				break;
			case ' ':
				MyWorld->MyActors.push_back(new AFloor(X, Y, ' ', false));
				break;
			case 'P':
				MyWorld->MyActors.push_back(new APlayer(X, Y, 'P', true));
				break;
			case 'G':
				MyWorld->MyActors.push_back(new AGoal(X, Y, 'G', false));
				break;
			case 'M':
				MyWorld->MyActors.push_back(new AMonster(X, Y, 'M', false));
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
		MyWorld->Tick();
		MyWorld->Render();
	}
}


void Engine::Terminate()
{
	delete MyWorld;
	MyWorld = nullptr;
}
