#include <errno.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char st_config_h[FILENAME_MAX];
const int NUM_FONTS = 3;

struct Font {
  char *font_title;
  char *font_name;
  int font_size;
  float font_spacing;
};

struct Font *init_fonts() {

  struct Font *fonts_ptr = malloc(sizeof(struct Font) * NUM_FONTS);

  struct Font fonts_arr[] = {
      {"JetBrains", "JetBrainsMonoNFM", 14, 1.0},
      {"Victor", "VictorMono NFP", 18, 1.0},
      {"Lekton", "Lekton Nerd Font Mono", 21, 0.9},
  };

  for (int i = 0; i < NUM_FONTS; i++) {
    fonts_ptr[i] = fonts_arr[i];
  }

  return fonts_ptr;
}

int main(int argc, char **argv) {

  // st terminal's configuration file
  snprintf(st_config_h, FILENAME_MAX, "%s/.config/st/config.h", getenv("HOME"));

  initscr();

  struct Font *fonts_arr = init_fonts();

  for (int i = 0; i < NUM_FONTS; i++) {
    addstr(("\t%s\n\n\n", fonts_arr[i].font_name));
    refresh();
  }

  getch();

  endwin();

  free(fonts_arr);

  return 0;
}
