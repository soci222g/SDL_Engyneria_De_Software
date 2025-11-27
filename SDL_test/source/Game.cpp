#include"Game.h"
#include"RenderManager.h"
#include"InputManager.h"
#include "SceneManager.h"
#include"GamePlay.h"
#include <cassert>

void Game::Init()
{
	RM->Init();
	RM->LoadTexture("resource/image.png");
	RM->LoadFont("resource/fonts/hyperspace.ttf");
	
	assert(SM->addScene("GamePlay", new GamePlay()));
	assert(SM->InitScene("GamePlay"));
	
	_isRunning = false;

	
}

void Game::HandleElement()
{
	_isRunning = IM->Listen();
	
}

void Game::Update()
{
	SM->UpdateCurrentScene();
}

void Game::Renderer()
{
	RM->ClearScreen();
	
	//aqui es caregan tots els renderes del joc

	SM->GetCurrentScene()->Render();

	RM->RenderSceen();
	
}

void Game::releas()
{
	SDL_DestroyRenderer(_renderer); // peta tot lo que es el renderer;
	SDL_DestroyWindow(_window); // peta tot lo que es relacionat amb el windows 
	SDL_Quit();

}



void Game::IntitSDL()
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		throw SDL_GetError();
	}
}

void Game::CreateWindiwAndRenderer()
{
	if (!SDL_CreateWindowAndRenderer(
		"Test",
		512, 512,
		SDL_WINDOW_RESIZABLE,
		&_window,
		&_renderer


	)) {
		throw SDL_GetError();
	}
}
