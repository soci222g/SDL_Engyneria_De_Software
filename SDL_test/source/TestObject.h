#pragma once
#include"RenderManager.h"
#include"ImageObject.h"
#include"InputManager.h"

class TestObject : public ImageObject {
public:
	TestObject()
		: ImageObject("resource/image.png", Vector2(0.f, 0.f), Vector2(306.0f, 506.0f))
	{

		_physics->SetLinearDrag(0.1f);
		_physics->SetAngularDrag(0.2f);

		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = randomPosition;
		_transform->rotation = 30.0f;
		_transform->scale = Vector2(0.5f, 0.5f);

	}

	void Update() override {
		if (IM->GetEvent(SDLK_S, KeyState::DOWN) || IM->GetEvent(SDLK_S, KeyState::HOLD)) {
			_physics->addForce(Vector2(0.f, 20.f));
		}
		else if (IM->GetEvent(SDLK_R, KeyState::DOWN) || IM->GetEvent(SDLK_R, KeyState::HOLD)) {
			_physics->addForque(30);
		}
		Object::Update();
		
	}
};