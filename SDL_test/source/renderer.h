#pragma once
#include"SDL3/SDL.h"
#include<string>


class Renderer
{
protected:

	SDL_Texture* _texture;
	SDL_FRect _sourceRect;
	SDL_FRect _destinationRect;


public:
	virtual void LoadTextura(std::string texturaPath, SDL_Renderer* renderer) = 0;
	virtual void update() = 0;
	virtual void Render(SDL_Renderer* renderer) = 0;
	virtual void SetDestinationRect(SDL_FRect rectangle) { _destinationRect = rectangle; };




};
