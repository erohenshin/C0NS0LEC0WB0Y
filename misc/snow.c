#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <stdlib.h>
#include <time.h>

#define SCREENW 640
#define SCREENH 480
#define SNOWAMT 800

typedef struct {
	int  x,y;
	char r,g,b,v;
} Pixel;

SDL_Surface *screen;
SDL_Event    event;
char  r,g,b;
Pixel snow[SNOWAMT];

void init() {
	r = rand()%127+0;
	g = rand()%127+0;
	b = rand()%127+0;
	int i;
	for(i=0;i<SNOWAMT;i++) {
		snow[i].x = rand()%SCREENW+0;
		snow[i].y = rand()%SCREENH+0;
		snow[i].r = rand()%255+128;
		snow[i].g = rand()%255+128;
		snow[i].b = rand()%255+128;
		snow[i].v = rand()%3+1;
	}
}

int main(int argc,char *argv[]) {	
	char running = 1;
	int i;
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTTHREAD);
	screen = SDL_SetVideoMode(SCREENW,SCREENH,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	SDL_WM_SetCaption("H4!1+5474N",NULL);
	srand (time(NULL));
	init();

	while(running) {
		if(SDL_PollEvent(&event)) {
			if(event.type==SDL_QUIT) running = 0;
			if(event.type==SDL_KEYDOWN) if(event.key.keysym.sym==SDLK_z) init();
		}
		                      
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, r,g,b));

		for(i=0;i<SNOWAMT;i++) {
			pixelRGBA(screen,snow[i].x,snow[i].y,snow[i].r,snow[i].g,snow[i].b,255);
			snow[i].x -= snow[i].v;
			snow[i].y += snow[i].v;
			
			if(snow[i].x<0)   { 
				snow[i].x = SCREENW; 
				snow[i].y = rand()%SCREENH+0;
				snow[i].r = rand()%255+128;
				snow[i].g = rand()%255+128;
				snow[i].b = rand()%255+128;
				snow[i].v = rand()%3+1; 
			}
			else if(snow[i].y>SCREENH) {    
				snow[i].x = rand()%SCREENW+0;
				snow[i].y = 0; 
				snow[i].r = rand()%255+128;
				snow[i].g = rand()%255+128;
				snow[i].b = rand()%255+128;
				snow[i].v = rand()%3+1; 
			}
		}
		
		SDL_Flip(screen);
		SDL_Delay(40);
	}

	SDL_FreeSurface(screen); screen = NULL;
	SDL_Quit();
	return 0;
}
