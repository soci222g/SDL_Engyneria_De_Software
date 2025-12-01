#pragma once
#include"Scene.h"
#include"button.h"
#include "SceneManager.h"

class MainMenu : public Scene
{
public:
	MainMenu() = default;

	void OnEnter() override {
		Button* butto = new Button([] {

			SM->SetNextScene("Gameplay");
			});
		_ui.push_back(butto);
	}
	void OnExit() override {
		Scene::OnExit();
	}

	void Update() override {
		Scene::Update();
	}
	void Render() override {
		Scene::Render();
	}



	
};

