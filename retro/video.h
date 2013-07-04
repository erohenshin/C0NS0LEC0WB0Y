#ifndef _VIDEO_H_
#define _VIDEO_H_

#define SCREENW 256
#define SCREENH 240
#define SHEETW  128
#define SHEETH  128
#define TILEW		8
#define TILEH		8

extern SDL_Surface *screen;
extern SDL_Surface *background;
extern SDL_Surface *sprite;
extern SDL_Rect bgClip[SHEETW/TILEW*SHEETH/TILEH];
extern SDL_Rect  sClip[SHEETW/TILEW*SHEETH/TILEH];

void loadVideo();
void exitVideo();
void drawBackground(int xStart,int yStart,SDL_Rect *clip);
void drawClip(int x,int y,SDL_Surface *source,SDL_Rect *clip);
void writeText(int x,int y,char *string);

#endif
