#pragma once
#include"RenderManager.h"
#include"ImageObject.h"

class TestObject : public ImageObject {
public:
	TestObject()
		: ImageObject("resource/image.png", Vector2(0.f, 0.f), Vector2(306.0f, 506.0f))
	{

		Vector2 randomPosition = Vector2(rand() % RM->WINDOW_WIDTH, rand() % RM->WINDOW_HEIGHT);
		_transform->position = randomPosition;
		_transform->rotation = 30.0f;
		_transform->scale = Vector2(0.5f, 0.5f);

	}

};