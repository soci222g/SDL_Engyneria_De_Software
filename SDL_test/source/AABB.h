#pragma once
#include"Vector2.h"

class AABB {
protected:
	Vector2 _topLeft;
	Vector2 _size;
public:
	AABB(Vector2 TopLeft, Vector2 size) : _topLeft(TopLeft), _size(size) {}
	Vector2 const GetTopLeft() { return _topLeft; }
	Vector2 const GetSize() { return _size; }
	void SetTopLeft(Vector2 newTopLeft) { _topLeft = newTopLeft; }
	void SetSize(Vector2 newsize) { _size = newsize; }


	bool ChechOverLapingPoint(Vector2 point);
	bool ChechOverLapingAABB(const AABB* other);
};