#include "TextRenderer.h"
#include "RenderManager.h"

void TextRenderer::Update(float dt)
{
	Vector2 offcet = (Vector2(-_tranform->size.x, -_tranform->size.y) / 2.0f) * _tranform->scale; //punto central del texto

	_destinationRect.x = _tranform->position.x + offcet.x;
	_destinationRect.y = _tranform->position.y + offcet.y;

	if (_autoSize) {
		_destinationRect.w = _sourceRect.w * _tranform->scale.x;
		_destinationRect.h = _sourceRect.h * _tranform->scale.y;
	}
	else {
		_destinationRect.w = _tranform->size.x * _tranform->scale.x;
		_destinationRect.h = _tranform->size.y * _tranform->scale.y;
	}

}

void TextRenderer::Render()
{
	SDL_RenderTextureRotated(
		RM->GetRenderer(),
		_textTexture,
		&_sourceRect,
		&_destinationRect,
		_tranform->rotation,
		NULL,
		SDL_FLIP_NONE
	);

}

void TextRenderer::SetText(std::string text)
{
	if (_textTexture != nullptr) //si ya hay una textura, te la cargas
		SDL_DestroyTexture(_textTexture);
	
	//creem una surfface amb la informacio nova
	SDL_Surface* surf = TTF_RenderText_Solid(
		RM->GetFont(_resourcePath),
		text.c_str(), 
		text.length(),
		_color
	);
	assert(surf);

	//crear textura
	_textTexture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surf);
	assert(_textTexture);
	//definim el rec del sourf face
	_sourceRect = { 0,0, (float)surf->w, (float)surf->h };
	//actualitzema la string
	_text = text;

}
