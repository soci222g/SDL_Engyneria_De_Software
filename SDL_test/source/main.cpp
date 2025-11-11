#include<SDL3/SDL.h>
#include <exception>
#include"Game.h"
#include"TimeManager.h"
#include <iostream>

int main() {
	Game game;
	
	try {

		game.Init();

	}
	catch (std::exception e) {
		std::cout << "Error: " << e.what();
		game.releas();
		return -1;
	}


	
	while (!game.IsRunning())
	{

		
		TIME->Update();
		std::cout << TIME->GetDeltaTime() << std::endl;
		if (TIME->ShouldUpdateGame()){

			game.HandleElement();
			game.Update();
			game.Renderer();
			TIME->RestartDeltaTime();
		}

	
		
	}
	game.releas();

	return 0;

}

