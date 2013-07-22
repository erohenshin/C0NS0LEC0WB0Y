#include <SDL/SDL.h>

SDL_Surface *screen;
SDL_Event    event;

int main(int argc,char *argv[]) {	
	char running = 1;
	
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTTHREAD);
	screen = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	SDL_WM_SetCaption("H4!1-5474N",NULL);
	
	while(running) {
		if(SDL_PollEvent(&event)) if(event.type==SDL_QUIT) running = 0;
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 170,0,170));
		
		/*DO SOME SHIT*/

		SDL_Flip(screen);
		SDL_Delay(25);
	}
	
	SDL_FreeSurface(screen); screen = NULL;
	SDL_Quit();
	return 0;
}
