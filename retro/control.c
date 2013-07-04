#include "SDL/SDL.h"
#include "object.h"
#include "game.h"

extern char running;

void getInput() {
	SDL_Event event;
	
	if(SDL_PollEvent(&event)) {
		if(event.type==SDL_QUIT) {
			running = 0;
		}
		if(event.type==SDL_KEYDOWN) {
			switch(event.key.keysym.sym) {
				case SDLK_UP:    player.yVel -= 2; break;
				case SDLK_DOWN:  player.yVel += 2; break;
				case SDLK_LEFT:  player.xVel -= 2; break;
				case SDLK_RIGHT: player.xVel += 2; break;
			}
		}
		if(event.type==SDL_KEYUP) {
			switch(event.key.keysym.sym) {
				case SDLK_UP:    player.yVel += 2; break;
				case SDLK_DOWN:	 player.yVel -= 2; break;
				case SDLK_LEFT:  player.xVel += 2; break;
				case SDLK_RIGHT: player.xVel -= 2; break;
			}
		}
	}
}
