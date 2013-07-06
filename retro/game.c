#include "SDL/SDL.h"
#include "object.h"
#include "game.h"
#include "video.h"

#include <string.h>

State gmState = TITLE;
int   gmLvl   = 0;

static int bgX, bgY;

Object player;
Object* someObject;

static char *message = "hail satan";
static char msgTime = 50;

void changeState(State changeTo) {
	gmState = changeTo;
	if(gmState == LEVEL) loadLevel(gmLvl);
}

void loadLevel(int lvl) {
	someObject       = (Object*) malloc (sizeof(Object));
	player.x         = (SCREENW>>1)-(TILEW>>1);
	player.y         = 0;
	player.xVel      = 0;
	player.yVel      = 0;
	player.w         = TILEW;
	player.h         = TILEH;
	player.clip      = &sClip[1];

	someObject->x    = (SCREENW>>1)-(TILEW>>1);
	someObject->y    = (SCREENH>>1)-(TILEH>>1);
	someObject->xVel = 0;
	someObject->yVel = 0;
	someObject->w    = TILEW;
	someObject->h    = TILEH;
	someObject->clip = &sClip[0];
	someObject->direction = LEFT;
	free(someObject);
	someObject = NULL;
}

void exitLevel() {
	free(someObject);
}

void updateGame() {
	if(msgTime>0) --msgTime;
  
	player.x += player.xVel;
	player.y += player.yVel;

	if      (player.x>SCREENW-TILEW) player.x = 0;
	else if (player.x<0)             player.x = SCREENW-TILEW;
	else if (player.y>SCREENH-TILEH) player.y = 0;
	else if (player.y<0)             player.y = SCREENH-TILEH;
	
	if(someObject != NULL) {
		if(!someObject->xVel) moveObject(someObject,someObject->direction,1);
		if(someObject->x<0) someObject->x = SCREENW-TILEW;
	
		someObject->x += someObject->xVel;
		someObject->y += someObject->yVel;
  
		if(xCollision(&player, someObject)) {
			player.x -= player.xVel << 1;
			someObject->x -= someObject->xVel;
			message = "hit!";
			msgTime = 50;
		}
		if(yCollision(&player, someObject)) {
			player.y -= player.yVel << 1;
			message = "hit!";
			msgTime = 50;
		}
		if(!yCollision(&player, someObject)) ++player.y;
		if( yCollision(&player, someObject)) --player.y;
	}
	
	bgX -= 1;
	bgY -= 1;

	if(bgX<=-TILEW) bgX = 0;
	if(bgY<=-TILEH) bgY = 0;
}

void renderGame() {
	drawBackground(bgX, bgY, bgClip);

	drawObject(&player, player.clip);
	
	if(someObject != NULL) {
		drawObject(someObject, someObject->clip);
	}
	writeText(0, 0, "r37r0 v0.0");
	if(msgTime>0) writeText((SCREENW>>1)-(TILEW*strlen(message)>>1), SCREENH-TILEH, message);
}
