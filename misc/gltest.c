//gcc -o test gltest.c -lSDL -lGL -lGLU

#include "SDL/SDL.h" 
#include "SDL/SDL_opengl.h" 

char running = 1;

SDL_Surface *screen;
SDL_Event   event;

void initialize() {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_WM_SetCaption("GLTEST", NULL);
  screen = SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);

  glClearColor(0,0,0,0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 800, 600, 0, -1, 1);
  
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void drawSomething() {
  glTranslatef(0, 0, 0);
  glBegin(GL_QUADS);
    glColor4f(1.0, 1.0, 1.0, 1.0);
    glVertex3f( 0, 0, 0 ); 
    glVertex3f( 300, 0, 0 ); 
    glVertex3f( 300, 150, 0 ); 
    glVertex3f( 0, 150, 0 ); 
  glEnd();
  glLoadIdentity();
}

void handleEvent() {
  while (SDL_PollEvent(&event)) if (event.type==SDL_QUIT) running=0;
}

int main(int argc, char* args[]) {
  initialize();
  
  while(running) {
    handleEvent();    
    glClear(GL_COLOR_BUFFER_BIT);
    drawSomething();
    SDL_GL_SwapBuffers();
  }
  
  SDL_FreeSurface(screen);
  screen = NULL;
  
  SDL_Quit();

  return 0;
}
