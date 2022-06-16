#pragma once
#include "World.h"
#include <fstream>
#include "ESpriteType.h"
#include "SDL.h"


#pragma comment(lib, "SDL2main.lib")
#pragma comment(lib, "SDL2.lib")


class Engine
{
public:
	Engine();
	virtual ~Engine();

	void Initialize();
	void Load(string MapFilename);
	void Run();
	void Terminate();
	void Input();

	void QuitGame() { bRunning = false; }

	const Uint64 GetWorldDeltaSeconds() { return DeltaSeconds; }

	inline static int GetKeyCode() {return Engine::KeyCode;} //inline ����ȭ �Ҷ� ��� 
	
	inline static Engine* GetEngine() {return Instance;} //const�� ���� ������ ���� �� �ٲٰ� �ϱ� ���ؼ�

	inline World* GetWorld() const {return MyWorld;}

	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;

	

protected:
	World* MyWorld;

	static int KeyCode; //�������ڸ��� �޸𸮿� ����Ǿ ��𼭵��� �ҷ��� �� �� �ִ�.

	static Engine* Instance;
	
	bool bRunning;

	Uint64 LastTick;
	Uint64 DeltaSeconds;
};

#define GEngine Engine::GetEngine()