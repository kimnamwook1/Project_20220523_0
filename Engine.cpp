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
	//	Myworld->MyActors.push_back(new AWall(i, 0, '#', true));// ���̿��忡 �ִ� ���̿��Ͷ�� ����Ʈ�� ���ο� ������ �߰��Ѵ�.
	//	Myworld->MyActors.push_back(new AWall(i, 9, '#', true));
	//}

	//for (int i = 1; i <= 8; ++i)
	//{
	//	Myworld->MyActors.push_back(new AWall(0, i, '#', true));
	//	Myworld->MyActors.push_back(new AWall(9, i, '#', true));
	//}


	//Myworld->MyActors.push_back(new APlayer(1, 1, 'P', true));
	//Myworld->MyActors.push_back(new AGoal(8, 8, 'G', true));
	ifstream MapFile(MapFilename); // �Է� ���� , ��ȣ �ȿ��� ���� �̸�

	int Y = 0;
	while (MapFile.peek() != EOF)//peek �� ���� �������� �Լ�
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
