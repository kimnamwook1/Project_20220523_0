#include "Engine.h"
#include <iostream>
#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")
#pragma comment(lib, "SDL2_mixer.lib")

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