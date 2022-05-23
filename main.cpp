#include <iostream>
#include <fstream>
#include "Engine.h"
#include "World.h"
#include <string>

using  namespace std;

int main()
{

	Engine* MyEngine = new Engine();
	MyEngine->Load("Level02.map");
	MyEngine->Run();
	
	delete MyEngine;
	MyEngine = nullptr;

		return 0;
}