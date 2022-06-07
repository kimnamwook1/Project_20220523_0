#pragma once
#include "World.h"
#include <fstream>
#include "ESpriteType.h"

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

	inline static int GetKeyCode() {return Engine::KeyCode;} //inline 최적화 할때 사용 
	
	inline static Engine* GetEngine() {return Instance;} //const를 쓰는 이유는 값을 못 바꾸게 하기 위해서

	inline World* GetWorld() const {return MyWorld;}

	void QuitGame() { bRunning = false; }

protected:
	World* MyWorld;

	static int KeyCode; //시작하자마자 메모리에 선언되어서 어디서든지 불러서 쓸 수 있다.

	static Engine* Instance;
	bool bRunning;

};

#define GEngine Engine::GetEngine()