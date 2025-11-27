#pragma once
#include"Scene.h"
#include "TestObject.h"

class GamePlay : public Scene
{
public:

	GamePlay() = default;

	void OnEnter() override {

		SPAWNER.addObject(new TestObject());
		SPAWNER.addObject(new TestObject());


	}

	void OnExit() override { Scene::OnExit(); }
	void Update() override { Scene::Update(); }
	void Render() override { Scene::Render(); }

};

