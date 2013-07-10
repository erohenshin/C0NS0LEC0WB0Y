#ifndef _OBJECT_H_
#define _OBJECT_H_

typedef enum { UP,DOWN,LEFT,RIGHT,STOP } Direction;

typedef struct {
	int x,y,w,h;
	int vel,xVel,yVel;
	int health;
	Direction direction;
	SDL_Rect *clip;
} Object;

void moveObject(Object *obj,Direction direction);
void drawObject(Object *obj,SDL_Rect *clip);
int xCollision(Object *obj1,Object *obj2);
int yCollision(Object *obj1,Object *obj2);

#endif
