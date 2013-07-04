#ifndef _GAME_H_
#define _GAME_H_

typedef enum {TITLE,LOAD,LEVEL,GAMEOVER} State;

extern int gmLvl;
extern State gmState;
extern Object player;

void loadLevel(int lvl);
void updateGame();
void renderGame();

#endif
