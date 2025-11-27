#pragma once
#include"Object.h"
#include"Spawner.h"

class Scene
{
protected:
	std::vector<Object*> _ui;
	std::vector<Object*> _Objects;

public:
	Scene() = default;


	virtual void OnEnter() = 0;
	virtual void OnExit() {

		SPAWNER.clearSpawn();

		for (Object* o : _Objects)
			delete o;
		_Objects.clear();

		for (Object* o : _ui) {
			delete o;
		}
		_ui.clear();
	}

	virtual void Update();

	virtual void Render() {
		for (Object* o : _Objects)
			o->Render();

		for (Object* UI : _ui)
			UI->Render();
	}

};

