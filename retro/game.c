#include "SDL/SDL.h"
#include "object.h"
#include "game.h"
#include "video.h"

State gmState = TITLE;
int   gmLvl   = 0;

static int bgX, bgY;

Object player;
Object someObject;

void loadLevel(int lvl) {
	player.x        = (SCREENW>>1)-(TILEW>>1);
	player.y        = 0;
	player.xVel     = 0;
	player.yVel     = 0;
	player.w        = TILEW;
	player.h        = TILEH;
	player.clip     = &sClip[1];

	someObject.x    = (SCREENW>>1)-(TILEW>>1);
	someObject.y    = (SCREENH>>1)-(TILEH>>1);
	someObject.w    = TILEW;
	someObject.h    = TILEH;
	someObject.clip = &sClip[0];
	someObject.direction = LEFT;

	gmState = LEVEL;
}

void updateGame() {
	player.x += player.xVel;
	player.y += player.yVel;

	if      (player.x>SCREENW-TILEW) player.x = 0;
	else if (player.x<0)             player.x = SCREENW-TILEW;
	else if (player.y>SCREENH-TILEH) player.y = 0;
	else if (player.y<0)             player.y = SCREENH-TILEH;
	
	if(!someObject.xVel) moveObject(&someObject,someObject.direction,1);
	if(someObject.x<0) someObject.x = SCREENW-TILEW;
	
	someObject.x += someObject.xVel;
	someObject.y += someObject.yVel;

	/*BASIC COLLISION*/
	if(xCollision(&player, &someObject)) {
		player.x -= player.xVel << 1;
		someObject.x -= someObject.xVel;
	}
	if(yCollision(&player, &someObject)) {
		player.y -= player.yVel << 1;
	}
	if(!yCollision(&player, &someObject)) ++player.y;
	if( yCollision(&player, &someObject)) --player.y;

	/*BASIC BG SCROLLING*/
	bgX -= 1;
	bgY -= 1;

	if(bgX<=-TILEW) bgX = 0;
	if(bgY<=-TILEH) bgY = 0;
}

void drawGame() {
	drawBackground(bgX, bgY, bgClip);

	drawObject(&player, player.clip);
	drawObject(&someObject, someObject.clip);

	writeText(0, 0, "r37r0 v0.0");
}
