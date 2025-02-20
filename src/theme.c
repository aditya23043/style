#include <regex.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* TODO:
 * vim
 * nvim
 * st
 * foot
 * gtk
 */

const int LINE_SIZE = 1024;
const char *temp_file_name =
    "theme_switcher_temp"; // put in $HOME/.cache/ directory

struct Themes_arr {
  struct Theme *theme_arr; // array containing all the themes
  int size;                // number of themes
};

struct Theme {

  char *theme_name;

  char *vim_colorscheme;
  char *vim_bg;

  char *bg;
  char *fg;
  char *suggestion;

  char *black;
  char *red;
  char *green;
  char *yellow;
  char *blue;
  char *magenta;
  char *cyan;
  char *white;
};

struct Themes_arr initialize_themes() {

  const struct Theme gruvbox = {
      "Gruvbox", "gruvbox", "dark",    "#282828", "#ebdbb2",
      "#484848", "#484848", "#fb4934", "#b8bb26", "#fabd2f",
      "#83a598", "#d3869b", "#8ec07c", "#fbf1c7",
  };

  const struct Theme gruvbox_material_dark = {
      "Gruvbox Material Dark",
      "gruvbox-material",
      "dark",
      "#141617",
      "#ddc7a1",
      "#242729",
      "#282828",
      "#ea6962",
      "#a9b665",
      "#d8a657",
      "#7daea3",
      "#d3869b",
      "#89b482",
      "#d4be98",
  };

  const struct Theme gruvbox_material_light = {
      "Gruvbox Material Light",
      "gruvbox-material",
      "light",
      "#ebdbb2",
      "#654735",
      "#dfcd9f",
      "#282828",
      "#c14a4a",
      "#6c782e",
      "#b47109",
      "#45707a",
      "#945e80",
      "#4c7a5d",
      "#dbddbf",
  };

  const struct Theme solarized_dark = {
      "Solarized Dark", "NeoSolarized", "dark",    "#839496", "#003d4d",
      "#002b36",        "#282828",      "#dc322f", "#859900", "#b58900",
      "#268bd2",        "#d33682",      "#2aa198", "#839496",
  };

  const struct Theme solarized_light = {
      "Solarized Light", "NeoSolarized", "light",   "#fcf0cf", "#576d75",
      "#e6d8b3",         "#282828",      "#dc322f", "#859900", "#b58900",
      "#268bd2",         "#d33682",      "#2aa198", "#839496",
  };

  struct Theme something[] = {
      gruvbox,        gruvbox_material_dark, gruvbox_material_light,
      solarized_dark, solarized_light,
  };

  struct Theme *theme_presets_ptr =
      malloc(sizeof(struct Theme) * sizeof(something) / sizeof(something[0]));

  for (int i = 0; i < sizeof(something) / sizeof(something[0]); i++) {
    theme_presets_ptr[i] = something[i];
  }

  struct Themes_arr final_themes_array = {
      theme_presets_ptr,
      sizeof(something) / sizeof(something[0]),
  };

  return final_themes_array;
}

bool vim_exists() {
  const char *vim_binaries[] = {"/usr/bin/vim",  "/usr/local/bin/vim",
                                "/bin/vim",      "/opt/vim/bin/vim",
                                "/usr/sbin/vim", NULL};

  for (int i = 0; vim_binaries[i] != NULL; i++) {
    if (access(vim_binaries[i], X_OK) == 0) {
      printf("VIM executable found at: %s\n", vim_binaries[i]);
      return true;
    }
  }
  return false;
}

void vim_theme_change(char *colorscheme_name, char *background) {

  if (access(("%s/.vimrc", getenv("HOME")), F_OK) == 0) {
    printf("VIM configuration file found at: $HOME/.vimrc\n");

    regex_t regex, regex2;
    regcomp(&regex, "^colorscheme", 0);
    regcomp(&regex2, "^set bg=", 0);

    char temp_filename[FILENAME_MAX];
    sprintf(temp_filename, "%s/.cache/%s", getenv("HOME"), temp_file_name);
    FILE *temp_file = fopen(temp_filename, "w");

    char vim_config_filename[FILENAME_MAX];
    sprintf(vim_config_filename, "%s/.vimrc", getenv("HOME"));

    FILE *vim_config_file = fopen(vim_config_filename, "r");

    if (vim_config_file == NULL) {
      printf("Unable to open VIM config file!\n");
      exit(-1);
    }

    char init_line[LINE_SIZE];
    char final_line[LINE_SIZE];

    while (fgets(init_line, LINE_SIZE, vim_config_file)) {
      int regex_value = regexec(&regex, init_line, 0, NULL, 0);
      int regex_value_2 = regexec(&regex2, init_line, 0, NULL, 0);

      if (regex_value == 0) {
        strcpy(final_line, "colorscheme ");
        strcat(final_line, colorscheme_name);
        strcat(final_line, "\n");
      } else if (regex_value_2 == 0) {
        strcpy(final_line, "set bg=");
        strcat(final_line, background);
        strcat(final_line, "\n");
      } else {
        strcpy(final_line, init_line);
      }

      fprintf(temp_file, "%s", final_line);
    }

    fclose(temp_file);
    fclose(vim_config_file);
    regfree(&regex);
    regfree(&regex2);

    // copy from temp file to actual config file
    temp_file = fopen(temp_filename, "r");
    vim_config_file = fopen(vim_config_filename, "w");

    while (fgets(init_line, LINE_SIZE, temp_file)) {
      fputs(init_line, vim_config_file);
    }

    fclose(temp_file);
    fclose(vim_config_file);

  } else {
    printf("Not able to access vim configuration file!\n");
    printf("Ensure that $HOME/.vimrc exists\n");
  }
}

struct Theme input_palette() {

  struct Themes_arr themes = initialize_themes();

  printf("\nSelect theme:\n");
  for (int i = 0; i < themes.size; i++) {
    printf("  %d. %s\n", i + 1, themes.theme_arr[i].theme_name);
  }

  printf("\n  Choose >> ");

  int selected_theme_index;
  scanf("%d", &selected_theme_index);

  if (selected_theme_index > themes.size || selected_theme_index < 0) {
    printf("Theme not found!\n");
    exit(-1);
  }

  struct Theme selected_theme = themes.theme_arr[selected_theme_index - 1];

  return selected_theme;
}

int main(int argc, char *argv[]) {

  struct Theme theme = input_palette();

  if (vim_exists()) {
    vim_theme_change(theme.vim_colorscheme, theme.vim_bg);
  }

  return 0;
}
