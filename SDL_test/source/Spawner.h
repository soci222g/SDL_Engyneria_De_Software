#pragma once
#include<queue>
#include"Object.h"
#define SPAWNER Spawner::Instanciate()
class Spawner
{

public:
	static Spawner& Instanciate() {
		static Spawner instance;
		return instance;
	}
	void addObject(Object* obj) { spawnerObjects.push(obj); }
	bool areThereObjectsInSpawner() { return !spawnerObjects.empty(); }
	void clearSpawn() {
		while (areThereObjectsInSpawner())
		{
			delete spawnerObjects.front();
			spawnerObjects.pop();
		}
	}

	Object* GetObject() {
		if (!areThereObjectsInSpawner()) {
			return nullptr;
		}

		Object* temp = spawnerObjects.front();
		spawnerObjects.pop();
		return temp;


	}


private:
	Spawner() = default;
	Spawner(Spawner&) = delete;
	Spawner& operator=(const Spawner) = delete;


	std::queue<Object*> spawnerObjects;
	std::queue<Object*> spawnerUIObjects;

};

