#include <iostream>
#include <fstream>
#include <conio.h> //inline ������ ��ó�� ����� �Ѵ�.
#include <algorithm>

#include "SDL_mixer.h"

#include "Engine.h"
#include "World.h"
#include "Wall.h"
#include "Player.h"
#include "Goal.h"
#include "Floor.h"
#include "Monster.h"
#include "SDL.h"
#include "ASound.h"
#include "Text.h"


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

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		SDL_Log("SDL_INIT_ERROR");
	}

	MyWindow = SDL_CreateWindow("Maze", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
	MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

	//���� �ʱ�ȭ
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	TTF_Init();
	

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
	int MaxX = 0;	
	while (MapFile.peek() != EOF)//peek==����� �� ����� ĭ���� // EOF =end of file
	{
		char Buffer[1024] = { 0, };
		MapFile.getline(Buffer, 1024); // �� ���� �о�Ͷ�.
		MaxX = strlen(Buffer);

		for (size_t X = 0; X < strlen(Buffer); ++X) // ������ ������� ����̱⿡ size_t�� ���
		{
		
			char Cursor = Buffer[X];
			switch (Cursor)
			{
			case '#':
				MyWorld->SpawnActor(new AWall((int)X, Y, '#', true));
				break;
			case 'P':
				MyWorld->SpawnActor(new APlayer((int)X, Y, 'P', false));
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

	SDL_SetWindowSize(MyWindow, MaxX * 60, Y * 60); //â ������ �ٲٱ�


	//�׸��� ������ ������ ����
	sort(MyWorld->MyActors.begin(), MyWorld->MyActors.end(), AActor::Compare);

	MapFile.close();

	MyWorld->SpawnActor(new ASound(100, 100, "data/bgm.mp3", -1));
	MyWorld->SpawnActor(new AText(100, 100, "Hello World", SDL_Color{ 255, 0, 0 }, 40));
}


void Engine::Run()
{
	MyWorld->BeginPlay();//run�� �� ���̿����� ����÷��� ������

	while (bRunning) //1Frame
	{
		DeltaSeconds = SDL_GetTicks64() - LastTick;
		Input();
		MyWorld->Tick();
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0x00, 0x00, 0xff);
		SDL_RenderClear(MyRenderer);

		MyWorld->Render();

		/*SDL_RenderFillRect(MyRenderer, new SDL_Rect{ 0, 0, 100, 100 });*/
		LastTick = SDL_GetTicks64();
		SDL_RenderPresent(MyRenderer);
	
	}
}


void Engine::Terminate()
{
	delete MyWorld;
	MyWorld = nullptr;

	SDL_DestroyRenderer(MyRenderer);
	SDL_DestroyWindow(MyWindow);
	SDL_Quit();
	TTF_Quit();

}

void Engine::Input()
{
	SDL_PollEvent(&MyEvent);//input
}
