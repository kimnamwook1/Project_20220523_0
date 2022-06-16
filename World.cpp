#include "World.h"

World::World()
{
}

World::~World()
{
	for (auto Actor : MyActors)
	{
		delete Actor;
	}
	MyActors.clear(); // 메모리에서 날리는 작업
}

void World::BeginPlay()
{
	for (auto Actor : MyActors) 
	{
		Actor->BeginPlay();
	}
}

void World::Tick()
{
	for (auto Actor : MyActors) // 마이 액터에 있는 것들을 하나씩 꺼내서 tick을 실행시켜주세요.
	{
		Actor->Tick();
	}
}

void World::Render()
{

	for (auto Actor : MyActors)
	{
		Actor->Render();
	}
}

void World::SpawnActor(AActor* NewActor)
{
	MyActors.push_back(NewActor);
}
