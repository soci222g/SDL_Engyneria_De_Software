#include "AABB.h"
#include "RigidBody.h"



bool RigidBody::CheckCollision(const RigidBody* other)
{

	for (AABB* ownCollider : _colliders) {
		for (AABB* OtherCollider : other->_colliders) {
			if (ownCollider->ChechOverLapingAABB(OtherCollider))
				return true;
		}
	}

	return false;
}

bool RigidBody::CheckOverlapingPoint(Vector2 point)
{
	for (AABB* ownCollider : _colliders) {
		if (ownCollider->ChechOverLapingPoint(point))
			return true;
	}

	return false;
}


void RigidBody::Update(float dt) {

	_velocity = _velocity + _acceleration * dt;
	_angularVelocity = _angularVelocity + _angularAcceleration * dt;

	_velocity = _velocity * (1 / (1 + dt * _linearDrag));
	_angularVelocity = _angularVelocity * (1 / (1 + dt * _angularDrag));

	_transform->position = _transform->position + _velocity * dt;
	_transform->rotation = _transform->rotation + _angularVelocity * dt;

	_acceleration = Vector2();
	_angularAcceleration = 0.f;

	Vector2 offset = (Vector2(_transform->size.x, _transform->size.y) / 2.0f) * _transform->scale;


	for (AABB* ownCollision : _colliders) {
		ownCollision->SetTopLeft(_transform->position + offset);
		ownCollision->SetSize(_transform->size * _transform->scale);

	}


}