#include "CApp.h"
#include <iostream>

int CApp::OnInit() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;

	Window_ = SDL_CreateWindow("PIG", 50, 50, 1280, 720, SDL_WINDOW_SHOWN);
	if (Window_ == NULL) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	
	Render_ = SDL_CreateRenderer(Window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Render_ == NULL) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return 2;
	}
	
	Surf_Display_Close_ = SDL_LoadBMP("pig.bmp");
	if (Surf_Display_Close_ == NULL) {
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		return 3;
	}	
	
	Surf_Display_Open_ = SDL_LoadBMP("pig1.bmp");
	if (Surf_Display_Open_ == NULL) {
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		return 4;
	}

	Pig_ = SDL_CreateTextureFromSurface(Render_, Surf_Display_Close_);

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}
	//Load sound effects
	GScratch_ = Mix_LoadWAV("pig.wav");
	if (GScratch_ == NULL)
	{
		printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}
}