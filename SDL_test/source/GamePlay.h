#pragma once
#include"Scene.h"
#include "TestObject.h"
#include"TextObject.h"

class GamePlay : public Scene
{
public:

	GamePlay() = default;

	void OnEnter() override {

		SPAWNER.addObject(new TestObject());
		SPAWNER.addObject(new TestObject());

		
		TextObject* Text1 = new TextObject("HOLi");
		Text1->GetTransform()->position = Vector2(200, 200);
		_ui.push_back(Text1);

	}

	void OnExit() override { Scene::OnExit(); }
	void Update() override { Scene::Update(); }
	void Render() override { Scene::Render(); }

};

