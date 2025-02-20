#include <errno.h>
#include <ncurses.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char st_config_filename[FILENAME_MAX];
char temp_filename[FILENAME_MAX];
const int NUM_FONTS = 3;
const int LINE_SIZE = 1024;

struct Font {
    char *font_title;
    char *font_name;
    char *font_weight;
    int font_size;
};

struct Font *init_fonts() {

    struct Font *fonts_ptr = malloc(sizeof(struct Font) * NUM_FONTS);

    struct Font fonts_arr[] = {
        {"JetBrains", "JetBrainsMonoNFM", "Bold", 14},
        {"Victor", "VictorMono NFP", "Bold", 18},
        {"Lekton", "Lekton Nerd Font Mono", "Bold", 21},
    };

    for (int i = 0; i < NUM_FONTS; i++) {
        fonts_ptr[i] = fonts_arr[i];
    }

    return fonts_ptr;
}

struct Font select_font() {

    initscr();
    noecho();
    curs_set(0);

    struct Font *fonts_arr = init_fonts();

    int chosen = 0;

    while (true) {

        // padding
        printw("\n");
        // list and highlight chosen font
        for (int i = 0; i < NUM_FONTS; i++) {
            if (chosen == i)
                attron(A_STANDOUT);
            printw(" %s \n", fonts_arr[i].font_name);
            if (chosen == i)
                attroff(A_STANDOUT);
            refresh();
        }

        char c = getch();

        // handle user input
        if (c == 'j') {
            if (chosen == NUM_FONTS - 1) {
                chosen = 0;
            } else {
                chosen++;
            }
        } else if (c == 'k') {
            if (chosen == 0) {
                chosen = NUM_FONTS - 1;
            } else {
                chosen--;
            }
        } else if (c == 'q' || c == '\n') {
            break;
        }

        clear();
    }

    endwin();

    struct Font selected_font = fonts_arr[chosen];

    // clean
    free(fonts_arr);

    return selected_font;
}

char *fgets_semicolon(int MAX_NUM_CHARS, FILE *file) {
    int i = 0;
    char c;
    char buffer[MAX_NUM_CHARS];

    while (i < MAX_NUM_CHARS - 1 && (c = fgetc(file)) != EOF && c != ';') {
        buffer[i++] = c;
    }
    if (c == ';') {
        buffer[i++] = ';';
    } else if (c == EOF) {
        return NULL;
    }
    buffer[i] = '\0';

    char *buffer_ptr = malloc(sizeof(char) * MAX_NUM_CHARS);

    for (int i = 0; i < MAX_NUM_CHARS; i++) {
        buffer_ptr[i] = buffer[i];
    }

    return buffer_ptr;
}

int main(int argc, char **argv) {

    // st terminal's configuration file
    snprintf(st_config_filename, FILENAME_MAX, "%s/.config/st/config.h",
             getenv("HOME"));

    // temp file
    snprintf(temp_filename, FILENAME_MAX, "%s/.cache/temp_font",
             getenv("HOME"));

    struct Font font = select_font();

    // change st config

    if (access(st_config_filename, F_OK) != 0) {
        printf(
            "ST configuration does not exist at $HOME/.config/st/config.h!\n");
        exit(-1);
    }

    FILE *st_conf = fopen(st_config_filename, "r");
    if (st_conf == NULL) {
        printf("Unable to ST configuration file!\n");
        exit(-1);
    }

    char final_line[LINE_SIZE];
    char *buffer;

    regex_t regex;
    regcomp(&regex, "static char \\*font =", 0);
    int regex_return;

    FILE *temp_file = fopen(temp_filename, "w");

    while (true) {
        buffer = fgets_semicolon(LINE_SIZE, st_conf);
        if (buffer == NULL)
            break;
        regex_return = regexec(&regex, buffer, 0, NULL, 0);
        if (regex_return == 0) {
            snprintf(final_line, LINE_SIZE,
                     "static char *font = "
                     "\"%s:style=%s:size=%d:antialias=true:autohint=true\";",
                     font.font_name, font.font_weight, font.font_size);
        } else {
            strcpy(final_line, buffer);
        }

        // putting the contents of the file with the modified font in a temp
        // file
        if (temp_file == NULL) {
            printf("Unable to open temporary file!\n");
            exit(-1);
        }
        fprintf(temp_file, "%s", final_line);

        free(buffer);
    }

    fprintf(temp_file, "\n");
    fclose(temp_file);
    fclose(st_conf);

    // mv <temp> .config/st/config.h
    rename(temp_filename, st_config_filename);

    char command[256];
    snprintf(command, 256, "cd %s/.config/st && sudo make clean install && cd",
             getenv("HOME"));
    char *cmd[] = {"/usr/bin/bash", "-c", command, NULL};
    int ret = execv(cmd[0], cmd);
    if (ret == 0) {
        printf("Font Changed Successfully!");
    } else {
        printf("ERROR: %s\n", strerror(errno));
    }

    return 0;
}
