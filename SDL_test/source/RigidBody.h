#pragma once
#include"AABB.h"
#include"transform.h"
#include<vector>

class RigidBody
{
private:
	std::vector<AABB*> _colliders;
	Transform* _transform;

	Vector2 _velocity;
	float _angularVelocity;

	Vector2 _acceleration;
	float _angularAcceleration;

	float _linearDrag;
	float _angularDrag;


public:
	RigidBody(Transform* transfomr) :
		_transform(transfomr), _velocity(Vector2()), _angularVelocity(0.f),
		_acceleration(Vector2()), _angularAcceleration(0.f),
		_linearDrag(0.f), _angularDrag(0.f) {}


	~RigidBody() {
		for (AABB* collider : _colliders) {
			delete collider;
		}
	}

	void addCollider(AABB* collider) { _colliders.push_back(collider); }

	void addForce(Vector2 force) { _acceleration = _acceleration + force;}
	void addForque(float amount) { _angularAcceleration +=  amount	;}


	Vector2 const  GetVeloci() { return _velocity; }
	void SetVelocity(Vector2 velocity) { _velocity = velocity; }
	void SetLinearDrag(float linearDrag) { _linearDrag = linearDrag; }
	void SetAngularDrag(float angularDrag) { _angularDrag = angularDrag; }

	bool CheckCollision(const RigidBody* other);
	bool CheckOverlapingPoint(Vector2 point);

	void Update(float dt);


};
