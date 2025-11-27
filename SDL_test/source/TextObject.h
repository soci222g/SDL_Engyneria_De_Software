#pragma once
#include"Object.h"
#include"TextRenderer.h"


class TextObject : public Object
{
public:
	TextObject(std::string text) : Object() {
		_render = new TextRenderer(_transform, text);
		_render->SetColor({ 0xff,0xff,0xff,0xff });
	}
	

	void SetText(std::string Text) {

		dynamic_cast<TextRenderer*>(_render)->SetText(Text);
	}
		
};

