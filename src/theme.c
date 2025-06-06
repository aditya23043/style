#include "theme.h"
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void) {

    setlocale(LC_ALL, "");

    initscr();
    curs_set(0);
    noecho();

    int focus = 0;

    while (true) {

        attroff(A_STANDOUT);
        attron(A_BOLD);
        printw("\n  SELECT THEME  \n\n");
        attroff(A_BOLD);

        for (int i = 0; i < sizeof(themes) / sizeof(themes[0]); i++) {
            attroff(A_STANDOUT);
            printw("  ");
            if (i == focus) {
                attron(A_STANDOUT);
            }
            printw(" %s \n", themes[i].name);
        }
        attroff(A_STANDOUT);

        printw("\n");
        printw("  ┌────────MAPPINGS─────────┐\n");
        printw("  │                         │\n");
        printw("  │ ↳ Down            j     │\n");
        printw("  │ ↳ Up              k     │\n");
        printw("  │ ↳ Select          Ret   │\n");
        printw("  │ ↳ Quit            q     │\n");
        printw("  │                         │\n");
        printw("  └─────────────────────────┘\n");

        int num_themes = sizeof(themes) / sizeof(themes[0]);

        char ch = getch();

        if (ch == 'j') {
            focus++;
            if (focus == num_themes)
                focus = 0;
        }
        if (ch == 'k') {
            focus--;
            if (focus == -1)
                focus = num_themes - 1;
        }
        if (ch == 'q') {
            clear();
            endwin();
            return 0;
        }
        if (ch == '\n') {
            break;
        }
        clear();
    }
    endwin();

    patch_st(focus);
    patch_vim(focus);
    patch_fish(focus);

    return 0;
}

/* CHANGES
 * Colorscheme
 */
int patch_st(int index) {
    FILE *config_file = fopen(ST_CONFIG_FILE, "r");
    FILE *temp_file = fopen(TEMP_FILE, "w");

    if (config_file == NULL) {
        perror("ST config file opening");
        return -1;
    }
    if (temp_file == NULL) {
        perror("temp file opening");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    long file_pos;

    char colorname[512];

    snprintf(colorname, 512, "static const char *colorname[] = { \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", [255] = 0, \"%s\", \"%s\", \"%s\", \"%s\" };\n", themes[index].black, themes[index].red, themes[index].green, themes[index].yellow, themes[index].blue, themes[index].magenta, themes[index].cyan, themes[index].white, themes[index].black, themes[index].red, themes[index].green, themes[index].yellow, themes[index].blue, themes[index].magenta, themes[index].cyan, themes[index].white, themes[index].fg, themes[index].bg, themes[index].fg, themes[index].bg);

    int flag = 0;
    int done = 0;
    while (fgets(buffer, BUFFER_SIZE, config_file) != NULL) {
        if (strstr(buffer, "colorname") == NULL && !flag) {
            fputs(buffer, temp_file);
        } else if (strstr(buffer, "colorname") != NULL && !done) {
            flag = 1;
            done = 1;
            fputs(colorname, temp_file);
        }
        if (strchr(buffer, '}') != NULL && flag) {
            flag = 0;
        }
    }

    fclose(temp_file);
    fclose(config_file);

    if (rename(TEMP_FILE, ST_CONFIG_FILE) == -1) {
        perror("RENAME");
		return -1;
    }

    system(ST_BUILD_CMD);

    return 0;
}

/* CHANGES:
 * Colorscheme
 * Background (dark/light)
 * Indent Line Color
 */
int patch_vim(int index) {
    FILE* config_file = fopen(VIM_CONFIG_FILE, "r");
    FILE* temp_file = fopen(TEMP_FILE, "w");

    if (config_file == NULL) {
        perror("ST config file opening");
        return -1;
    }
    if (temp_file == NULL) {
        perror("temp file opening");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    char colorscheme[128];
    char bg[128];
    char indentline[128];

    snprintf(colorscheme, sizeof(colorscheme), "colorscheme %s\n", themes[index].vim_name);
    snprintf(bg, sizeof(bg), "set bg=%s\n", themes[index].vim_bg);
    snprintf(indentline, sizeof(indentline), "let g:indentLine_color_gui = \"%s\"\n", themes[index].suggestion);

    while (fgets(buffer, BUFFER_SIZE, config_file) != NULL) {
        if (strstr(buffer, "colorscheme") != NULL) {
            fputs(colorscheme, temp_file);
        } else if (strstr(buffer, "set bg=") != NULL) {
            fputs(bg, temp_file);
        } else if (strstr(buffer, "let g:indentLine_color_gui") != NULL) {
            fputs(indentline, temp_file);
        } else {
            fputs(buffer, temp_file);
        }
    }

    fclose(config_file);
    fclose(temp_file);

    if (rename(TEMP_FILE, VIM_CONFIG_FILE) == -1) {
        perror("RENAME");
		return -1;
    }

    return 0;
}

int patch_fish(int index) {
    FILE *config_file = fopen(FISH_CONFIG_FILE, "r");
    FILE *temp_file = fopen(TEMP_FILE, "w");

    if (config_file == NULL) {
        perror("ST config file opening");
        return -1;
    }
    if (temp_file == NULL) {
        perror("temp file opening");
        return -1;
    }

    char buffer[BUFFER_SIZE];
    char suggestion[128];

    snprintf(suggestion, sizeof(suggestion), "set -U fish_color_autosuggestion \"%s\"\n", themes[index].suggestion);

    while (fgets(buffer, BUFFER_SIZE, config_file) != NULL) {
        if (strstr(buffer, "fish_color_autosuggestion") != NULL) {
            fputs(suggestion, temp_file);
        } else {
            fputs(buffer, temp_file);
        }
    }

    if (rename(TEMP_FILE, FISH_CONFIG_FILE) == -1) {
        perror("RENAME");
		return -1;
    }

    fclose(config_file);
    fclose(temp_file);

    return 0;
}
