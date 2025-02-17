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
const char *temp_file_name = "theme_switcher_temp";

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

void vim_theme_change() {

  if (access(("%s/.vimrc", getenv("HOME")), F_OK) == 0) {
    printf("VIM configuration file found at: $HOME/.vimrc\n");

    regex_t regex, regex2;
    regcomp(&regex, "^colorscheme", 0);
    regcomp(&regex2, "^set bg=", 0);

    FILE *temp_file = fopen(temp_file_name, "w");
    FILE *vim_config_file = fopen(("%s/.vimrc", getenv("HOME")), "r");

    char init_line[LINE_SIZE];
    char final_line[LINE_SIZE];

    while (fgets(init_line, LINE_SIZE, vim_config_file)) {
      int regex_value = regexec(&regex, init_line, 0, NULL, 0);
      int regex_value_2 = regexec(&regex2, init_line, 0, NULL, 0);

      if (regex_value == 0) {
        strcpy(final_line, "colorscheme ");
        strcat(final_line, "nord");
        strcat(final_line, "\n");
      } else if (regex_value_2 == 0) {
        strcpy(final_line, "set bg=");
        strcat(final_line, "light");
        strcat(final_line, "\n");
      } else {
        strcpy(final_line, init_line);
      }

      fprintf(temp_file, "%s", final_line);
    }

    printf(final_line);
    fclose(temp_file);
    fclose(vim_config_file);
    regfree(&regex);
    regfree(&regex2);
  }
}

int main(int argc, char *argv[]) {
  if (vim_exists()) {
    vim_theme_change();
  }
  return 0;
}
