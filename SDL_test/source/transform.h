#pragma once
#include"Vector2.h"


class Trnsform
{
public:
	Vector2 position;
	float rotation;
	Vector2 scale;


	Trnsform()
		: position(Vector2(0.0f,0.0f)), rotation(0.f), scale(Vector2(1.0f, 1.0f)){}

	Trnsform(Vector2 _position, float _rotation, Vector2 _scale)
		: position(_position), rotation(_rotation), scale(_scale) {	}

};




