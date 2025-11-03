#pragma once
#include"renderer.h"
#include"RenderManager.h"


class ImageRenderer : public Renderer
{
public:
	ImageRenderer(Transform* tranform, std::string resourcePath, Vector2 sourceOffset, Vector2 sourceSize);

	
	virtual void Update(float dt) override;
	virtual void Render() override;

};


