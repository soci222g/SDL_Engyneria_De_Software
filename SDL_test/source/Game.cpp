#include"Game.h"
#include"ImageObject.h"
#include"RenderManager.h"
#include"TestObject.h"
#include"InputManager.h"
void Game::Init()
{
	RM->Init();
	RM->LoadTexture("resource/image.png");
	_isRunning = false;
	
	TestObject* test1 = new TestObject();
	_gameObjects.push_back(test1);
	TestObject* test2 = new TestObject();
	_gameObjects.push_back(test2);
}

void Game::HandleElement()
{
	_isRunning = IM->Listen();
	
}

void Game::Update()
{
	for (Object* go : _gameObjects)
		go->Update();


}

void Game::Renderer()
{
	RM->ClearScreen();
	
	//aqui es caregan tots els renderes del joc

	for (Object* go : _gameObjects)
		go->Render();

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
