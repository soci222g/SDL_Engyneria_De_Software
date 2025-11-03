#pragma once

#include"Object.h"
#include<SDL3/SDL.h>
#include<vector>

class Game
{
public:
	Game() = default;

	void Init();
	void HandleElement();
	void Update();
	void Renderer();
	void releas();

	bool IsRunning() const { return _isRunning; };
private:
	void IntitSDL();
	void CreateWindiwAndRenderer();

	bool _isRunning;
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::vector<Object*> _gameObjects;

};

