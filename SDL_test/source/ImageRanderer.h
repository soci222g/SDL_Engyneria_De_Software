#pragma once
#include"renderer.h"


class ImageRenderer : public Renderer
{
public:
	void LoadTextura(std::string texturaPath, SDL_Renderer* renderer) override;
	 void update() override;
	 void Render(SDL_Renderer* renderer) override;

};


