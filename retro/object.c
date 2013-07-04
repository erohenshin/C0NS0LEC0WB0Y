#include "SDL/SDL.h"
#include "object.h"
#include "video.h"

void moveObject(Object *obj,Direction direction,int vel) {
	switch(direction) {
		case UP:		obj->yVel -= vel; break;
		case DOWN:  obj->yVel += vel; break;
		case LEFT:  obj->xVel -= vel; break;
		case RIGHT: obj->xVel -= vel; break;
	}
}

void drawObject(Object *obj,SDL_Rect *clip) {
	drawClip(obj->x, obj->y, sprite, clip);
}

int xCollision(Object *obj1,Object *obj2) {
	return obj1->y + obj1->h > obj2->y &&
		 		 obj1->y < obj2->y + obj2->h &&
				 obj1->x + obj1->w > obj2->x &&
		 		 obj1->x < obj2->x + obj2->w;
}

int yCollision(Object *obj1,Object *obj2) {
	return obj1->x + obj1->w > obj2->x &&
		 		 obj1->x < obj2->x + obj2->w && 
				 obj1->y + obj1->h > obj2->y &&
		 		 obj1->y < obj2->y + obj2->h;
}
