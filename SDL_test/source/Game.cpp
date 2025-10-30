#include"Game.h"
#include"ImageObject.h"
void Game::Init()
{
	IntitSDL();
	CreateWindiwAndRenderer();
	SDL_SetRenderDrawColor(
		_renderer,
		255, 0, 0, 0xFF
	);

	_isRunning = true;

	_gameObjects.push_back(new ImageObject("resource/image.png", _renderer));

}

void Game::HandleElement()
{
	SDL_Event event; //amb aixo gestionem tots els events. 
	while (SDL_PollEvent(&event))
		if (event.type == SDL_EVENT_QUIT) //mira si los tipos de eventos machea, en este caso si has cerado el juego
			_isRunning = false;
}

void Game::Update()
{
	for (Object* go : _gameObjects)
		go->update();
}

void Game::Renderer()
{

	SDL_RenderClear(_renderer);
	//aqui es caregan tots els renderes del joc

	for (Object* go : _gameObjects)
		go->Render(_renderer);


	SDL_RenderPresent(_renderer);
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
