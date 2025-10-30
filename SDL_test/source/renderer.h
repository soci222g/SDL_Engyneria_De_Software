#pragma once
#include"SDL3/SDL.h"
#include<string>
#include"transform.h"


class Renderer
{
protected:

	Trnsform* _tranform;
	SDL_Color _color;
	SDL_FRect _sourceRect;
	SDL_FRect _destinationRect;
	std::string _resourcePath;


public:

	Renderer(Trnsform* transform, std::string path)
		: _tranform(transform), _resourcePath(path) {}


	virtual void update() = 0;
	virtual void Render() = 0;
	virtual void SetDestinationRect(SDL_FRect rectangle) { _destinationRect = rectangle; };


	void SetColot(SDL_Color color) { _color = color; }
	SDL_Color GetColor() { return _color; }
};
