#include "ImageRanderer.h"
#include<cassert>
#include<SDL3_image/SDL_image.h>

ImageRenderer::ImageRenderer(Transform* tranform, std::string resourcePath, Vector2 sourceOffset, Vector2 sourceSize)
	: Renderer(tranform, resourcePath)
{
	RM->GetTexture(resourcePath);

	_sourceRect = SDL_FRect{
		sourceOffset.x,
		sourceOffset.y,
		sourceSize.x,
		sourceSize.y
	};

	_destinationRect = SDL_FRect{
		tranform->position.x,
		tranform->position.y,
		tranform->scale.x,
		tranform->scale.y
	};
}



void ImageRenderer::Update(float dt)
{
	Vector2 offset = (Vector2(-_tranform->size.x, -_tranform->size.y) / 2.0f) * _tranform->scale;

	_destinationRect.x = _tranform->position.x + offset.x;
	_destinationRect.y = _tranform->position.y + offset.y;

	_destinationRect.w = _tranform->scale.x * _tranform->size.x;
	_destinationRect.h = _tranform->scale.y* _tranform->size.y;
}



void ImageRenderer::Render()
{
	SDL_RenderTextureRotated(
		RM->GetRenderer(),
		RM->GetTexture(_resourcePath),
		&_sourceRect,
		&_destinationRect,
		_tranform->rotation,
		NULL,
		SDL_FLIP_NONE
	);
}
