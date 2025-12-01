#pragma once
#include"ImageObject.h"
#include"TextObject.h"
#include <functional>

class Button : public ImageObject
{
public:
	typedef std::function<void()> OnClick;


private:
	bool _IsHovered = false;
	OnClick _onClick;
public:
	Button(OnClick onClick);

	virtual void Update() override;
	virtual void Render() override;
private:

	 void OnHoverEnter();
	 void OnHoverExit();
	 void OnClicked();


};



