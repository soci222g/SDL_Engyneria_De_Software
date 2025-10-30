#include "ImageRanderer.h"
#include<cassert>
#include<SDL3_image/SDL_image.h>

void ImageRenderer::LoadTextura(std::string texturaPath, SDL_Renderer* renderer)
{
	_texture = IMG_LoadTexture(renderer, texturaPath.c_str());
	assert(_texture);

	_sourceRect = { 0.0f, 0.0f, (float)_texture->w, (float)_texture->h };
}

void ImageRenderer::update()
{

	//update
}

void ImageRenderer::Render(SDL_Renderer* renderer)
{
	SDL_RenderTexture(renderer, _texture, &_sourceRect, &_destinationRect);
}
