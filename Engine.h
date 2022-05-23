#pragma once
#include "World.h"
#include <fstream>

class Engine
{
public:
	Engine();
	virtual ~Engine();

	World* Myworld;
	bool bRunning;

	void Initialize();
	void Load(string MapFilename);
	void Run();
	void Terminate();
};

