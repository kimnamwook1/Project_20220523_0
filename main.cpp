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
	if (SDL_Init(SDL_INIT_VIDEO) < 0) // �׷��� ī�� �ʱ�ȭ
	{
		SDL_Log("SDL_INIT_ERROR");
		return -1;
	}
	//������ â �����
	SDL_Window* MyWindow = SDL_CreateWindow("Maze", 100, 100, 800, 600, SDL_WINDOW_OPENGL);
	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);

	bool bRunning = true;
	SDL_Event MyEvent;
	int X = 0;
	while (bRunning)// ���ѷ����ε� shift f5������ ����
	{
		SDL_PollEvent(&MyEvent);//�������Ӹ��� ����� �����쿡 ~~�߳�?

		switch (MyEvent.type)
		{
		case SDL_QUIT:
			bRunning = false;
			break;
		case SDL_KEYDOWN:
			SDL_Log("Press Key");
			break;
		}
		
		//�׷���ī�尡 �� �� ��� ,�� ĥ�� �غ�
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0x00, 0x00, 0xff);
		SDL_RenderClear(MyRenderer);

		//Actor �׷�
		SDL_SetRenderDrawColor(MyRenderer, 0xff, 0xff, 0x00, 0xff);
		SDL_RenderDrawRect(MyRenderer, new SDL_Rect{ 0, 100,100,100 });
		SDL_RenderFillRect(MyRenderer, new SDL_Rect{ X++ ,0,100,100 });

		//��ϵ� �� ����
		SDL_RenderPresent(MyRenderer);
	}
	//���������� �����ؾ� �ϴµ� ���Ŵ� ������ ��������
	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();

	return 0;
}