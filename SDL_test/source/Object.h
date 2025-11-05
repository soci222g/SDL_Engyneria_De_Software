#pragma once
#include "transform.h"
#include"renderer.h"
#include "RigidBody.h"
#include<SDL3/SDL.h>
#include<string>

class  Object
{
private:
	bool _isPendingDestroy = false;
protected:
	RigidBody* _physics;
	Transform* _transform;
	Renderer* _render = nullptr;

public:
	Object() {
		_transform = new Transform(); 
		_physics = new RigidBody(_transform);
	}
	~Object() {
		delete _transform;
		delete _render;
		delete _physics;
	}

	 Transform* GetTransform() { return _transform; }
	 virtual void Update() { 
		 if (_physics != nullptr)
			 _physics->Update(0.02f);
		 _render->Update(0.02f); } //50 FPS
	 virtual void Render() { _render->Render(); }
	 RigidBody* GetRigidBody() { return _physics; }

	 bool IsPrivateDestroy() { return _isPendingDestroy; }
	 virtual void Destroy() { _isPendingDestroy = true; }
};
