#include "Engine.h"
#include <iostream>
#include "SDL.h"

#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")

using namespace std;

int SDL_main(int argc, char* argv[])
{
	Engine* MyEngine = new Engine();
	MyEngine->Load("Level02.map");
	MyEngine->Run();

	delete MyEngine;
	MyEngine = nullptr;

	return 0;
}