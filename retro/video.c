#include "SDL/SDL_image.h"
#include "video.h"

SDL_Surface *screen;

SDL_Surface *background;
SDL_Surface *sprite;
SDL_Rect bgClip[CLIPS];
SDL_Rect  sClip[CLIPS];

void loadVideo() {
	screen = SDL_SetVideoMode(SCREENW,SCREENH,8,SDL_HWSURFACE|SDL_DOUBLEBUF);
  	SDL_WM_SetCaption("R37R0 v0.0",NULL);

	SDL_Surface *loadImage;
	
	loadImage = IMG_Load("resource/test.png");
	background = SDL_DisplayFormatAlpha(loadImage);
	SDL_FreeSurface(loadImage);
	
	loadImage = IMG_Load("resource/tile.png");
	sprite = SDL_DisplayFormatAlpha(loadImage);
	SDL_FreeSurface(loadImage);
	
	int i, x=0, y=0;
	
	for(i=0;i<CLIPS;i++) {
		bgClip[i].x = x;
		bgClip[i].y = y;
		bgClip[i].w = TILEW;
		bgClip[i].h = TILEH;

		sClip[i].x  = x;
		sClip[i].y  = y;
		sClip[i].w  = TILEW;
		sClip[i].h  = TILEH;
		
		x = x+TILEW;
		
		if(x==SHEETW) {
			x  = 0;
			y += TILEH;
		}
	}
}

void exitVideo() {
	SDL_FreeSurface(background);
	SDL_FreeSurface(sprite);
	SDL_FreeSurface(screen);
}

void drawBackground(int xStart,int yStart,SDL_Rect *clip) {
	int x, y;	
	
	for(y=yStart;y<SCREENH;y+=TILEH) {
		for(x=xStart;x<SCREENW;x+=TILEW) {
			drawClip(x, y, background, &clip[45]);
		}
	}
}

void drawClip(int x,int y,SDL_Surface *source,SDL_Rect *clip) {
	if(x>=-TILEW && x<=SCREENW && y>=-TILEH && y<=SCREENH) {	
		SDL_Rect offset;
		offset.x = x;
		offset.y = y;
		SDL_BlitSurface(source, clip, screen, &offset);
	}
}

void writeText(int x,int y,char *string) {
	int i, ltr;
	
	for(i=0;string[i]!='\0';i++) {
		switch (string[i]) {
			case ' ': ltr=0;  break;
			case '0': ltr=1;  break;
			case '1': ltr=2;  break;
			case '2': ltr=3;  break;
			case '3': ltr=4;  break;
			case '4': ltr=5;  break;
			case '5': ltr=6;  break;
			case '6': ltr=7;  break;
			case '7': ltr=8;  break;
			case '8': ltr=9;  break;
			case '9': ltr=10; break;
			case 'a': ltr=11; break;
			case 'b': ltr=12; break;
			case 'c': ltr=13; break;
			case 'd': ltr=14; break;
			case 'e': ltr=15; break;
			case 'f': ltr=16; break;
			case 'g': ltr=17; break;
			case 'h': ltr=18; break;
			case 'i': ltr=19; break;
			case 'j': ltr=20; break;
			case 'k': ltr=21; break;
			case 'l': ltr=22; break;
			case 'm': ltr=23; break;
			case 'n': ltr=24; break;
			case 'o': ltr=25; break;
			case 'p': ltr=26; break;
			case 'q': ltr=27; break;
			case 'r': ltr=28; break;
			case 's': ltr=29; break;
			case 't': ltr=30; break;
			case 'u': ltr=31; break;
			case 'v': ltr=32; break;
			case 'w': ltr=33; break;
			case 'x': ltr=34; break;
			case 'y': ltr=35; break;
			case 'z': ltr=36; break;
			case '.': ltr=37; break;
			case '!': ltr=38; break;
			case '?': ltr=39; break;
		}
		drawClip(x, y, background, &bgClip[ltr]);
		x += TILEW;
	}
}
