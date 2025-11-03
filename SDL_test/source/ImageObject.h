#pragma once
#include"Object.h"
#include"ImageRanderer.h"

class ImageObject : public Object {
public:
	ImageObject(std::string texturePath, Vector2 sourceOffset, Vector2 sourceSize) : Object() {
		_render = new ImageRenderer(_transform, texturePath, sourceOffset, sourceSize);
	}
};
