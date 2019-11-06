#include  "CApp.h"

void CApp::OnCleanup() {
	SDL_DestroyTexture(Pig_);
	SDL_DestroyRenderer(Render_);
	SDL_DestroyWindow(Window_);

	SDL_FreeSurface(Surf_Display_Close_);
	SDL_FreeSurface(Surf_Display_Open_);

	Mix_FreeChunk(GScratch_);

	SDL_Quit();
	Mix_Quit();

}