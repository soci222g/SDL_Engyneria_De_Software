#pragma once
#include"renderer.h"
#include"SDL3/SDL.h"
#include"SDL3_ttf/SDL_ttf.h"
#include<cassert>

#define FONT_PATH "resource/fonts/hyperspace.ttf"


class TextRenderer : public Renderer
{
protected:
	std::string _text;
	SDL_Texture* _textTexture;
	bool _autoSize;

public:
	TextRenderer(Transform* tranform, std::string text) : Renderer(tranform, FONT_PATH) {
		SetText(text);
	}

	~TextRenderer() {
		SDL_DestroyTexture(_textTexture);
		_textTexture = nullptr;
	}
	void Update(float dt) override;
	void Render() override;
	void SetText(std::string text);
	void SetColor(SDL_Color color) override {
		Renderer::SetColor(color);
		SetText(_text);
	}
};

