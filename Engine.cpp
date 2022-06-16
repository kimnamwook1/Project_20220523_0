#include <iostream>
#include <fstream>
#include <conio.h> //inline 쓰려면 전처리 해줘야 한다.
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


int Engine::KeyCode = 0; //헤더에 선언만 하고 cpp에 초기화 해야한다.

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

	//사운드 초기화
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	TTF_Init();
	

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
	int MaxX = 0;	
	while (MapFile.peek() != EOF)//peek==몇번쨰 줄 몇번쨰 칸인지 // EOF =end of file
	{
		char Buffer[1024] = { 0, };
		MapFile.getline(Buffer, 1024); // 한 줄을 읽어와라.
		MaxX = strlen(Buffer);

		for (size_t X = 0; X < strlen(Buffer); ++X) // 버퍼의 사이즈는 양수이기에 size_t를 사용
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
			MyWorld->SpawnActor(new AFloor((int)X, Y, ' ', false)); // 바닥을 그리고 그 위에 액터가 올라가야하기 떄문

		}
		Y++;
	}

	SDL_SetWindowSize(MyWindow, MaxX * 60, Y * 60); //창 사이즈 바꾸기


	//그리는 순간의 순서를 변경
	sort(MyWorld->MyActors.begin(), MyWorld->MyActors.end(), AActor::Compare);

	MapFile.close();

	MyWorld->SpawnActor(new ASound(100, 100, "data/bgm.mp3", -1));
	MyWorld->SpawnActor(new AText(100, 100, "Hello World", SDL_Color{ 255, 0, 0 }, 40));
}


void Engine::Run()
{
	MyWorld->BeginPlay();//run할 때 마이월드의 비긴플레이 실행해

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
