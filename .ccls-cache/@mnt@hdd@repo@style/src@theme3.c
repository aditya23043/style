#include <ncurses.h>
#include <stdio.h>
#include "theme3.h"

int main(void) {

    initscr();
    curs_set(0);

    int focus = 0;


    while (true) {

        for (int i = 0; i < sizeof(themes) / sizeof(themes[0]); i++) {
            attroff(A_STANDOUT);
            if (i == focus) {
                attron(A_STANDOUT);
            }
            printw("%s\n", themes[i].name);
        }

        int num_themes = sizeof(themes)/sizeof(themes[0]);

        char ch = getch();

        if (ch == 'j') {
            focus++;
            if(focus == num_themes) focus = 0;
        }
        if (ch == 'k') {
            focus--;
            if(focus == -1) focus = num_themes-1;
        }
        if (ch == 'q') {
            return 0;
        }
        if (ch == '\n') {
            break;
        }
        clear();
    }
    endwin();

    patch_st();


    return 0;
}
