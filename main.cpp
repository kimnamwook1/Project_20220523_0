//#include <iostream>
//#include <string>
//#include <fstream>
#include "Engine.h"
#include "SDL.h"

#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2main.lib")

using  namespace std;

//int main()
//{
//	Engine* MyEngine = new Engine();
//	MyEngine->Load("Level01.map");
//	MyEngine->Run();
//	
//	delete MyEngine;
//	MyEngine = nullptr;
//
//		return 0;
//}

int SDL_main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) // 그래픽 카드 초기화
	{
		SDL_Log("SDL_INIT_ERROR");
		return -1;
	}
	//윈도우 창 만들기
	SDL_Window* MyWindow = SDL_CreateWindow("Maze", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

	bool bRunning = true;
	SDL_Event MyEvent;
	int X = 0;
	while (bRunning)// 무한루프인데 shift f5누르면 멈춤
	{
		SDL_PollEvent(&MyEvent);//매프레임마다 물어본다 윈도우에 ~~했냐?

		switch (MyEvent.type)
		{
		case SDL_QUIT:
			bRunning = false;
			break;
		case SDL_KEYDOWN:
			SDL_Log("Press Key");
			break;
		}
		
		//그래픽카드가 할 일 등록 ,붓 칠할 준비
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0x00, 0x00, 0xff);
		SDL_RenderClear(MyRenderer);

		//Actor 그려
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0x00, 0xff);
		SDL_RenderDrawRect(MyRenderer, new SDL_Rect{ 0, 100,100,100 });
		SDL_RenderFillRect(MyRenderer, new SDL_Rect{ X++ ,0,100,100 });

		//등록된 일 시작
		SDL_RenderPresent(MyRenderer);
	}
	//생성했으면 제거해야 하는데 제거는 생성의 역순으로
	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();

	return 0;
}