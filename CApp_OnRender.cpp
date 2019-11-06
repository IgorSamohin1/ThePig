#include "CApp.h"


void CApp::OnRender() {
	SDL_RenderClear(Render_);
	SDL_RenderCopy(Render_, Pig_, NULL, NULL);
	SDL_RenderPresent(Render_);
}