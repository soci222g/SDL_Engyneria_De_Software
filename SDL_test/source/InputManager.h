#pragma once
#include"SDL3/SDL.h"
#include<unordered_map>

#define IM InputManager::GetInstance()

enum KeyState {EMPTY, DOWN, UP, HOLD, RELISE};

class InputManager {
public:
		
	static InputManager* GetInstance() {
		static InputManager instance;
		return &instance;
	}
	bool Listen();

	float GetMouseX() { return _mouseX; }
	float GetMouseY() { return _mouseY; }
	bool GetLeftClick() { return leftClick; }
	bool GetEvent(Sint32 input, KeyState inputEvent);

private:
	InputManager() = default;
	InputManager(InputManager&) = delete;
	InputManager& operator=(const InputManager) = delete;
	~InputManager() {}

	float _mouseX, _mouseY;

	bool leftClick;


	std::unordered_map<Sint32, KeyState> _keyReferences;
};
