#pragma once
#include "Vector2.h"
#include"renderer.h"
#include<SDL3/SDL.h>
#include<string>

class  Object
{
protected:
	Vector2 _pos;
	Renderer* _render;

public:
	Object() { _pos = Vector2(); _render = nullptr; };
	void SetPosition(Vector2 position)
	{
		_pos = position;
		_render->SetDestinationRect({ _pos.x,_pos.y,100.0f,100.0f });
	}
	 Vector2 GetPosition() const { return _pos; }
	 void update() { _render->update(); }
	 void Render(SDL_Renderer* renderer) { _render->Render(renderer); }
};
