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

	inline static int GetKeyCode() {return Engine::KeyCode;} //inline ����ȭ �Ҷ� ��� 
	
	inline static Engine* GetEngine() {return Instance;} //const�� ���� ������ ���� �� �ٲٰ� �ϱ� ���ؼ�

	inline World* GetWorld() const {return MyWorld;}

	void QuitGame() { bRunning = false; }

protected:
	World* MyWorld;

	static int KeyCode; //�������ڸ��� �޸𸮿� ����Ǿ ��𼭵��� �ҷ��� �� �� �ִ�.

	static Engine* Instance;
	bool bRunning;

};

#define GEngine Engine::GetEngine()