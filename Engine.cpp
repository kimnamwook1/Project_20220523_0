#include <iostream>
#include <fstream>
#include <conio.h> //inline ������ ��ó�� ���࿩ �Ѵ�.
#include <algorithm>

#include "Engine.h"
#include "World.h"
#include "Wall.h"
#include "Player.h"
#include "Goal.h"
#include "Floor.h"
#include "Monster.h"

int Engine::KeyCode = 0; //����� ���� �ϰ� cpp�� �ʱ�ȭ �ؾ��Ѵ�.

Engine* Engine::Instance = nullptr;

Engine::Engine()
{
	Instance = this;
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
	while (MapFile.peek() != EOF)//peek==����� �� ����� ĭ���� // EOF =end of file
	{
		char Buffer[1024] = { 0, };
		MapFile.getline(Buffer, 1024); // �� ���� �о�Ͷ�.

		for (size_t X = 0; X < strlen(Buffer); ++X) // ������ ������� ����̱⿡ size_t�� ���
		{
			char Cursor = Buffer[X];
			switch (Cursor)
			{
			case '#':
				MyWorld->SpawnActor(new AWall((int)X, Y, '#', true));
				break;
			case 'P':
				MyWorld->SpawnActor(new APlayer((int)X, Y, 'P', true));
				break;
			case 'G':
				MyWorld->SpawnActor(new AGoal((int)X, Y, 'G', false));
				break;
			case 'M':
				MyWorld->SpawnActor(new AMonster((int)X, Y, 'M', false));
				break;
			}
			MyWorld->SpawnActor(new AFloor((int)X, Y, ' ', false)); // �ٴ��� �׸��� �� ���� ���Ͱ� �ö󰡾��ϱ� ����

		}
		Y++;
	}
	//�׸��� ������ ������ ����
	sort(MyWorld->MyActors.begin(), MyWorld->MyActors.end(), AActor::Compare);

	MapFile.close();
}


void Engine::Run()
{
	while (bRunning) //1Frame
	{
		Input();
		MyWorld->Tick();
		MyWorld->Render();
	}
}


void Engine::Terminate()
{
	delete MyWorld;
	MyWorld = nullptr;
}

void Engine::Input()
{
	Engine::KeyCode = _getch();
}
