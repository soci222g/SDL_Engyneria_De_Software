#pragma once
#include"Object.h"
#include"ImageRanderer.h"

class ImageObject : public Object {
public:
	ImageObject(std::string texturaPath, SDL_Renderer* renderer) {
		_render = new ImageRenderer();
		_render->LoadTextura(texturaPath, renderer);
		_render->SetDestinationRect({_pos.x,_pos.y, 100.0f,100.0f});

	}
	~ImageObject() {
		delete _render;
	}
};
