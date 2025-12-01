#include "button.h"
#include "InputManager.h"

Button::Button(OnClick onClick)
	: ImageObject("resource/button.png", Vector2(0.f, 0.f), Vector2(306.0f, 506.0f))
{
	_onClick = onClick;

	_transform->position = Vector2(100.0f, 100.f);
	_transform->scale = Vector2(1.0f, 1.f);
	_physics->addCollider(new AABB(_transform->position, _transform->scale));
}

void Button::Update()
{
	if (!_IsHovered && _physics->CheckOverlapingPoint({ (float)IM->GetMouseX(),(float)IM->GetMouseY() })) {
		OnHoverEnter();
	}
	else if (_IsHovered && !_physics->CheckOverlapingPoint({ (float)IM->GetMouseX(),(float)IM->GetMouseY() })) {
		OnHoverExit();
	}
	else if (_IsHovered && IM->GetLeftClick())
		OnClicked();

	Object::Update();
}

void Button::Render()
{
	Object::Render();
}

void Button::OnHoverEnter()
{
	//place holder rotation
	_transform->rotation = 90;
	_IsHovered = true;
}

void Button::OnHoverExit()
{
	//placeHolder
	_transform->rotation = 0;
	_IsHovered = false;
}

void Button::OnClicked()
{
	_onClick();
}
