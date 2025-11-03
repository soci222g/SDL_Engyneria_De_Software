#pragma once
#include "transform.h"
#include"renderer.h"
#include<SDL3/SDL.h>
#include<string>

class  Object
{
private:
	bool _isPendingDestroy = false;
protected:
	Transform* _transform;
	Renderer* _render = nullptr;

public:
	Object() {
		_transform = new Transform(); 
	}
	~Object() {
		delete _transform;
		_transform = nullptr;

		delete _render;
		_render = nullptr;
	}

	 Transform* GetTransform() { return _transform; }
	 virtual void update() { _render->Update(0.02f); } //50 FPS
	 virtual void Render() { _render->Render(); }

	 bool IsPrivateDestroy() { return _isPendingDestroy; }
	 virtual void Destroy() { _isPendingDestroy = true; }
};
