#include  <iostream>
#include "CApp.h"
#include "getRandomInRange.cpp"


void CApp::OnEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT) {
		Running_ = false;
	}else if (Event->type == SDL_KEYDOWN || Event->type == SDL_MOUSEBUTTONDOWN) {
		SDL_DestroyTexture(Pig_);
		Pig_ = SDL_CreateTextureFromSurface(Render_, Surf_Display_Open_);

		Mix_PlayChannel(-1, GScratch_, 0);

	}else if (Event->type == SDL_KEYUP || Event->type == SDL_MOUSEBUTTONUP) {
		SDL_DestroyTexture(Pig_);
		Pig_ = SDL_CreateTextureFromSurface(Render_, Surf_Display_Close_);
	}
}