#include <ncurses.h>

#define UP    'A'
#define DOWN  'B'
#define LEFT  'D'
#define RIGHT 'C'

int main() {
	char running = 1;
	char keyPress;
	
	initscr();
	raw();
	noecho();
	
	while(running) {
            keyPress=getch();
	    clear();
            switch(keyPress) {
                case UP:    printw("UP!");    break;
                case DOWN:  printw("DOWN!");  break;
                case LEFT:  printw("LEFT!");  break;
                case RIGHT: printw("RIGHT!"); break;
                case 'q':   running = 0;      break;
            }
            refresh();
	}
	endwin();
	return 0;
}
