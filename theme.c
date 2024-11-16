#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

struct _palette {

    char nvim_colorscheme[256];
    char* nvim_background;
    char* bg;
    char* fg;
    char* suggestion;
    char* black;
    char* red;
    char* green;
    char* yellow;
    char* blue;
    char* magenta;
    char* cyan;
    char* white;
    char* dwm_sel_fg;
    char* dwm_norm_fg;
    char* dwm_accent;

};

int main(){

    // ----------------------------------------------------------------DEFINING STUFF----------------------------------------------------------------

    char *st_conf_filename = "/home/adi/.config/st/config.h";
    char *fish_conf_filename = "/home/adi/.config/fish/config.fish";
    char *vim_conf_filename = "/home/adi/.vimrc";
    char *nvim_conf_filename = "/home/adi/.config/nvim/plugin/color.lua";
    char *ibl_conf_filename = "/home/adi/.config/nvim/lua/plugins/ibl.lua";
    char *dwm_conf_filename = "/home/adi/.config/dwm/config.h";
    char *temp_filename = "temp.h";

    const int LINE_SIZE = 512;

    char init_line[LINE_SIZE];
    char final_line[LINE_SIZE];

    regex_t regex;
    int regex_value;

    regex_t regex_2;
    int regex_2_value;

    regex_t regex_3;
    int regex_3_value;

    regex_t regex_4;
    int regex_4_value;

    FILE *st_conf_file;
    FILE *fish_conf_file;
    FILE *nvim_conf_file;
    FILE *vim_conf_file;
    FILE *ibl_conf_file;
    FILE *dwm_conf_file;
    FILE *temp_file;

    // ----------------------------------------------------------------INPUT PROMPT-----------------------------------------------------------------

    printf("\nTHEMES\n\n  1. Gruvbox Dark\n  2. Gruvbox Light\n  3. Solarized Dark\n  4. Solarized Light\n  5. Onedark Dark\n  6. Tokyonight Dark\n  7. Ok Colors Dark\n  8. Ok Colors Light\n  9. Dracula\n  10. Morhetz's Gruvbox\n  11. Jellybeans\n\n");
    printf("Choose a theme: ");
    int choice;
    scanf("%d", &choice);

    // ----------------------------------------------------------------SETTING PALETTE--------------------------------------------------------------

    struct _palette palette;

    switch(choice){

        // Gruvbox Dark
        case 1:
            strncpy(palette.nvim_colorscheme, "gruvbox-material", sizeof("gruvbox-material"));
            palette.nvim_background = "dark";
            palette.fg = "#ddc7a1";
            palette.suggestion = "#242729";
            palette.bg = "#141617";
            palette.black = "#282828";
            palette.red = "#ea6962";
            palette.green = "#a9b665";
            palette.yellow = "#d8a657";
            palette.blue = "#7daea3";
            palette.magenta = "#d3869b";
            palette.cyan = "#89b482";
            palette.white = "#d4be98";
            palette.dwm_sel_fg = "#000000";
            palette.dwm_norm_fg = "#888888";
            palette.dwm_accent = palette.blue;
            break;

            // Gruvbox Light
        case 2:
            strncpy(palette.nvim_colorscheme, "gruvbox-material", sizeof("gruvbox-material"));
            palette.nvim_background = "light";
            palette.fg = "#654735";
            palette.suggestion = "#dfcd9f";
            palette.bg = "#ebdbb2";
            palette.black = "#282828";
            palette.red = "#c14a4a";
            palette.green = "#6c782e";
            palette.yellow = "#b47109";
            palette.blue = "#45707a";
            palette.magenta = "#945e80";
            palette.cyan = "#4c7a5d";
            palette.white = "#dbddbf";
            palette.dwm_sel_fg = "#000000";
            palette.dwm_norm_fg = "#888888";
            palette.dwm_accent = palette.red;
            break;

            // Solarized Dark
        case 3:
            strncpy(palette.nvim_colorscheme, "solarized", sizeof("solarized"));
            palette.nvim_background = "dark";
            palette.fg = "#839496";
            palette.suggestion = "#003d4d";
            palette.bg = "#002b36";
            palette.black = "#282828";
            palette.red = "#dc322f";
            palette.green = "#859900";
            palette.yellow = "#b58900";
            palette.blue = "#268bd2";
            palette.magenta = "#d33682";
            palette.cyan = "#2aa198";
            palette.white = "#839496";
            palette.dwm_sel_fg = "#000000";
            palette.dwm_norm_fg = "#888888";
            palette.dwm_accent = palette.cyan;
            break;

            // Solarized Light
        case 4:
            strncpy(palette.nvim_colorscheme, "solarized", sizeof("solarized"));
            palette.nvim_background = "light";
            palette.fg = "#002b36";
            palette.suggestion = "#e4decd";
            palette.bg = "#fdf6e3";
            palette.black = "#282828";
            palette.red = "#dc322f";
            palette.green = "#859900";
            palette.yellow = "#b58900";
            palette.blue = "#268bd2";
            palette.magenta = "#d33682";
            palette.cyan = "#2aa198";
            palette.white = "#839496";
            palette.dwm_sel_fg = "#000000";
            palette.dwm_norm_fg = "#888888";
            palette.dwm_accent = palette.cyan;
            break;

            // Onedark
        case 5:
            strncpy(palette.nvim_colorscheme, "onedark", sizeof("onedark"));
            palette.nvim_background = "dark";
            palette.fg = "#abb2bf";
            palette.suggestion = "#2c303a";
            palette.bg = "#16181d";
            palette.black = "#282c34";  
            palette.red = "#e06c75";  
            palette.green = "#98c379";  
            palette.yellow = "#e5c07b";  
            palette.blue = "#61afef";  
            palette.magenta = "#c678dd";  
            palette.cyan = "#56b6c2";  
            palette.white = "#c5cad3";  
            palette.dwm_sel_fg = "#000000";
            palette.dwm_norm_fg = "#888888";
            palette.dwm_accent = palette.red;
            break;

            // Tokyonight
        case 6:
            strncpy(palette.nvim_colorscheme, "tokyonight-night", sizeof("tokyonight-night"));
            palette.nvim_background = "dark";
            palette.fg = "#c0caf5";
            palette.suggestion = "#1f202e";
            palette.bg = "#15161e";
            palette.black = "#2a2c3c";
            palette.red = "#f7768e";
            palette.green = "#9ece6a";
            palette.yellow = "#e0af68";
            palette.blue = "#7aa2f7";
            palette.magenta = "#bb9af7";
            palette.cyan = "#7dcfff";
            palette.white = "#cbd0e6";
            palette.dwm_sel_fg = "#000000";
            palette.dwm_norm_fg = "#888888";
            // palette.dwm_accent = "#73daca";
            palette.dwm_accent = palette.magenta;
            break;

            // Ok colors
        case 7:
            strncpy(palette.nvim_colorscheme, "okcolors-sharp", sizeof("okcolors-sharp"));
            palette.nvim_background = "dark";
            palette.fg = "#fefcf4";
            palette.suggestion = "#212126";
            palette.bg = "#010102";
            palette.black = "#212126";
            palette.red = "#fe989b";
            palette.green = "#24d998";
            palette.yellow = "#e0b316";
            palette.blue = "#5cc6fc";
            palette.magenta = "#fb8ed5";
            palette.cyan = "#19d2d7";
            palette.white = "#e0ded8";  
            palette.dwm_sel_fg = "#000000";
            palette.dwm_norm_fg = "#888888";
            palette.dwm_accent = palette.green;
            break;

        case 8:
            strncpy(palette.nvim_colorscheme, "okcolors-sharp", sizeof("okcolors-sharp"));
            palette.nvim_background = "light";
            palette.fg = "#000000";
            palette.suggestion = "#e0ded8";
            palette.bg = "#fefcf4";
            palette.black = "#212126";
            palette.red = "#d01a41";
            palette.green = "#17865d";
            palette.yellow = "#8b6e09";
            palette.blue = "#0a7caa";
            palette.magenta = "#c30d97";
            palette.cyan = "#0c8285";
            palette.white = "#e0ded8";  
            palette.dwm_sel_fg = "#000000";
            palette.dwm_norm_fg = "#888888";
            palette.dwm_accent = palette.red;
            break;

        case 9:
            strncpy(palette.nvim_colorscheme, "dracula", sizeof("dracula"));
            palette.nvim_background = "dark";
            palette.fg = "#F8F8F2";
            palette.suggestion = "#282a36";
            palette.bg = "#16171d";
            palette.black = "#282a36";
            palette.red = "#FF5555";
            palette.green = "#50FA7B";
            palette.yellow = "#F1FA8C";
            palette.blue = "#0a7caa";
            palette.magenta = "#BD93F9";
            palette.cyan = "#8BE9FD";
            palette.white = "#F8F8F2";  
            palette.dwm_sel_fg = "#000000";
            palette.dwm_norm_fg = "#888888";
            palette.dwm_accent = palette.magenta;
            break;

        case 10:
            strncpy(palette.nvim_colorscheme, "gruvbox", sizeof("gruvbox"));
            palette.nvim_background = "dark";
            palette.fg = "#ebdbb2";
            palette.suggestion = "#484848";
            palette.bg = "#282828";
            palette.black = "#484848";
            palette.red = "#fb4934";
            palette.green = "#b8bb26";
            palette.yellow = "#fabd2f";
            palette.blue = "#83a598";
            palette.magenta = "#d3869b";
            palette.cyan = "#8ec07c";
            palette.white = "#fbf1c7";  
            palette.dwm_sel_fg = "#000000";
            palette.dwm_norm_fg = "#888888";
            palette.dwm_accent = palette.magenta;
            break;

        case 11:
            strncpy(palette.nvim_colorscheme, "jellybeans", sizeof("jellybeans"));
            palette.nvim_background = "dark";
            palette.fg = "#e8e8d3";
            palette.suggestion = "#353535";
            palette.bg = "#151515";
            palette.black = "#3b3b3b";
            palette.red = "#cf6a4c";
            palette.green = "#99ad6a";
            palette.yellow = "#d8ad4c";
            palette.blue = "#597bc5";
            palette.magenta = "#a037b0";
            palette.cyan = "#71b9f8";
            palette.white = "#adadad";
            palette.dwm_sel_fg = "#000000";
            palette.dwm_norm_fg = "#888888";
            palette.dwm_accent = palette.green;
            break;

        default:
            printf("\nPick your theme from the following:\n\n  Gruvbox Light\n  Gruvbox Dark\n  Solarized Dark\n  Solarized Light\n");
            return 1;
    }

    // ----------------------------------------------------------------BACKEND----------------------------------------------------------------

    regex_value = regcomp(&regex, "static const char .colorname", 0);

    st_conf_file = fopen(st_conf_filename, "r");
    temp_file = fopen(temp_filename, "w");

    while( fgets(init_line, LINE_SIZE, st_conf_file) ){
        regex_value = regexec(&regex, init_line, 0, NULL, 0);

        if (regex_value == 0){
            strncpy(final_line, "static const char *colorname[] = { \"", sizeof("static const char *colorname[] = { \""));
            strncat(final_line, palette.black, sizeof(palette.black));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.red, sizeof(palette.red));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.green, sizeof(palette.green));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.yellow, sizeof(palette.yellow));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.blue, sizeof(palette.blue));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.magenta, sizeof(palette.magenta));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.cyan, sizeof(palette.cyan));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.white, sizeof(palette.white));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.black, sizeof(palette.black));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.red, sizeof(palette.red));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.green, sizeof(palette.green));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.yellow, sizeof(palette.yellow));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.blue, sizeof(palette.blue));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.magenta, sizeof(palette.magenta));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.cyan, sizeof(palette.cyan));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.white, sizeof(palette.white));
            strncat(final_line, "\", ", sizeof("\", "));
            strncat(final_line, "[255] = 0, \"", sizeof("[255] = 0, \""));
            strncat(final_line, palette.fg, sizeof(palette.fg));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.bg, sizeof(palette.bg));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.fg, sizeof(palette.fg));
            strncat(final_line, "\", \"", sizeof("\", \""));
            strncat(final_line, palette.bg, sizeof(palette.bg));
            strncat(final_line, "\" };\n", sizeof("\" };\n"));
        } else {
            strncpy(final_line, init_line, sizeof(init_line));
        }

        fprintf(temp_file, "%s", final_line);
    }

    fclose(temp_file);
    fclose(st_conf_file);

    // ----------------------------------------------------------------TEMP -> FINAL----------------------------------------------------------------

    st_conf_file = fopen(st_conf_filename, "w");
    temp_file = fopen(temp_filename, "r");

    while( fgets(init_line, LINE_SIZE, temp_file) ){
        fprintf(st_conf_file, "%s", init_line);
    }

    fclose(temp_file);
    fclose(st_conf_file);

    // ----------------------------------------------------------------FISH AUTOSUGGESTION COLOR----------------------------------------------------

    regex_value = regcomp(&regex, "set -U fish_color_autosuggestion", 0);

    fish_conf_file = fopen(fish_conf_filename, "r");
    temp_file = fopen(temp_filename, "w");

    while( fgets(init_line, LINE_SIZE, fish_conf_file) ){
        regex_value = regexec(&regex, init_line, 0,  NULL, 0);

        if (regex_value == 0){
            strncpy(final_line, "set -U fish_color_autosuggestion \"", sizeof("set -U fish_color_autosuggestion \""));
            strncat(final_line, palette.suggestion, sizeof(palette.suggestion));
            strncat(final_line, "\"\n", sizeof("\"\n"));
        } else {
            strncpy(final_line, init_line, sizeof(init_line));
        }

        fprintf(temp_file, "%s", final_line);
    }

    fclose(temp_file);
    fclose(fish_conf_file);

    // ----------------------------------------------------------------TEMP -> FINAL----------------------------------------------------

    fish_conf_file = fopen(fish_conf_filename, "w");
    temp_file = fopen(temp_filename, "r");

    while( fgets(init_line, LINE_SIZE, temp_file) ){
        fprintf(fish_conf_file, "%s", init_line);
    }

    fclose(temp_file);
    fclose(fish_conf_file);

    // ----------------------------------------------------------------NEOVIM COLORSCHEME----------------------------------------------------

    /* regex_value = regcomp(&regex, "vim.cmd.colorscheme", 0); */
    /* regex_2_value = regcomp(&regex_2, "vim.opt.background", 0); */

    /* nvim_conf_file = fopen(nvim_conf_filename, "r"); */
    /* temp_file = fopen(temp_filename, "w"); */

    /* while( fgets(init_line, LINE_SIZE, nvim_conf_file) ){ */
    /*     regex_value = regexec(&regex, init_line, 0,  NULL, 0); */
    /*     regex_2_value = regexec(&regex_2, init_line, 0,  NULL, 0); */

    /*     if (regex_value == 0){ */
    /*         strncpy(final_line, "vim.cmd.colorscheme \"", sizeof("vim.cmd.colorscheme \"")); */
    /*         strncat(final_line, palette.nvim_colorscheme, sizeof(palette.nvim_colorscheme)); */
    /*         strncat(final_line, "\"\n", sizeof("\"\n")); */
    /*     } else if (regex_2_value == 0){ */
    /*         strncpy(final_line, "vim.opt.background = \"", sizeof("vim.opt.background = \"")); */
    /*         strncat(final_line, palette.nvim_background, sizeof(palette.nvim_background)); */
    /*         strncat(final_line, "\"\n", sizeof("\"\n")); */
    /*     } else { */
    /*         strncpy(final_line, init_line, sizeof(init_line)); */
    /*     } */

    /*     fprintf(temp_file, "%s", final_line); */
    /* } */

    /* fclose(temp_file); */
    /* fclose(nvim_conf_file); */

    /* // ----------------------------------------------------------------TEMP -> FINAL---------------------------------------------------------------- */

    /* nvim_conf_file = fopen(nvim_conf_filename, "w"); */
    /* temp_file = fopen(temp_filename, "r"); */

    /* while( fgets(init_line, LINE_SIZE, temp_file) ){ */
    /*     fprintf(nvim_conf_file, "%s", init_line); */
    /* } */

    /* fclose(temp_file); */
    /* fclose(nvim_conf_file); */

    /* // ----------------------------------------------------------------INDENT BLANKLINE---------------------------------------------------- */

    /* regex_value = regcomp(&regex, "vim.api.nvim_set_hl", 0); */

    /* ibl_conf_file = fopen(ibl_conf_filename, "r"); */
    /* temp_file = fopen(temp_filename, "w"); */

    /* while( fgets(init_line, LINE_SIZE, ibl_conf_file) ){ */
    /*     regex_value = regexec(&regex, init_line, 0,  NULL, 0); */

    /*     if (regex_value == 0){ */
    /*         strncpy(final_line, "\t\t\tvim.api.nvim_set_hl(0, \"iblHighlighted\", { fg = \"", sizeof("\t\t\tvim.api.nvim_set_hl(0, \"iblHighlighted\", { fg = \"")); */
    /*         strncat(final_line, palette.suggestion, sizeof(palette.suggestion)); */
    /*         strncat(final_line, "\" })\n", sizeof("\" })\n")); */
    /*     } else { */
    /*         strncpy(final_line, init_line, sizeof(init_line)); */
    /*     } */

    /*     fprintf(temp_file, "%s", final_line); */
    /* } */

    /* fclose(temp_file); */
    /* fclose(ibl_conf_file); */

    /* // ----------------------------------------------------------------TEMP -> FINAL---------------------------------------------------------------- */

    /* ibl_conf_file = fopen(ibl_conf_filename, "w"); */
    /* temp_file = fopen(temp_filename, "r"); */

    /* while( fgets(init_line, LINE_SIZE, temp_file) ){ */
    /*     fprintf(ibl_conf_file, "%s", init_line); */
    /* } */

    /* fclose(temp_file); */
    /* fclose(ibl_conf_file); */

    // ----------------------------------------------------------------VIM COLORSCHEME------------------------------------------------------------

    regex_value = regcomp(&regex, "^colorscheme", 0);

    vim_conf_file = fopen(vim_conf_filename, "r");
    temp_file = fopen(temp_filename, "w");

    while( fgets(init_line, LINE_SIZE, vim_conf_file) ){
        regex_value = regexec(&regex, init_line, 0,  NULL, 0);

        if (regex_value == 0){
            strncpy(final_line, "colorscheme " , sizeof("colorscheme "));
            strncat(final_line, palette.nvim_colorscheme, sizeof(palette.nvim_colorscheme));
            strncat(final_line, "\n", sizeof("\n"));
        } else {
            strncpy(final_line, init_line, sizeof(init_line));
        }

        fprintf(temp_file, "%s", final_line);
    }

    fclose(temp_file);
    fclose(vim_conf_file);

    // ----------------------------------------------------------------TEMP -> FINAL----------------------------------------------------

    vim_conf_file = fopen(vim_conf_filename, "w");
    temp_file = fopen(temp_filename, "r");

    while( fgets(init_line, LINE_SIZE, temp_file) ){
        fprintf(vim_conf_file, "%s", init_line);
    }

    fclose(temp_file);
    fclose(vim_conf_file);

    // ----------------------------------------------------------------DWM COLORS CONFIG----------------------------------------------------

    regex_value = regcomp(&regex, "static const char norm_bg", 0);
    regex_2_value = regcomp(&regex_2, "static const char norm_fg", 0);
    regex_3_value = regcomp(&regex_3, "static const char sel_fg", 0);
    regex_4_value = regcomp(&regex_4, "static const char accent_col", 0);

    dwm_conf_file = fopen(dwm_conf_filename, "r");
    temp_file = fopen(temp_filename, "w");

    while( fgets(init_line, LINE_SIZE, dwm_conf_file) ){
        regex_value = regexec(&regex, init_line, 0,  NULL, 0);
        regex_2_value = regexec(&regex_2, init_line, 0,  NULL, 0);
        regex_3_value = regexec(&regex_3, init_line, 0,  NULL, 0);
        regex_4_value = regexec(&regex_4, init_line, 0,  NULL, 0);

        if (regex_value == 0){
            strncpy(final_line, "static const char norm_bg[] = \"", sizeof("static const char norm_bg[] = \""));
            strncat(final_line, palette.bg, sizeof(palette.bg));
            strncat(final_line, "\";\n", sizeof("\";\n"));
        } else if (regex_2_value == 0){
            strncpy(final_line, "static const char norm_fg[] = \"", sizeof("static const char norm_fg[] = \""));
            strncat(final_line, palette.dwm_norm_fg, sizeof(palette.dwm_norm_fg));
            strncat(final_line, "\";\n", sizeof("\";\n"));
        } else if (regex_3_value == 0){
            strncpy(final_line, "static const char sel_fg[] = \"", sizeof("static const char sel_fg[] = \""));
            strncat(final_line, palette.dwm_sel_fg, sizeof(palette.dwm_sel_fg));
            strncat(final_line, "\";\n", sizeof("\";\n"));
        } else if (regex_4_value == 0){
            strncpy(final_line, "static const char accent_col[] = \"", sizeof("static const char accent_col[] = \""));
            strncat(final_line, palette.dwm_accent, sizeof(palette.dwm_accent));
            strncat(final_line, "\";\n", sizeof("\";\n"));
        } else {
            strncpy(final_line, init_line, sizeof(init_line));
        }

        fprintf(temp_file, "%s", final_line);
    }

    fclose(temp_file);
    fclose(dwm_conf_file);

    // ----------------------------------------------------------------TEMP -> FINAL----------------------------------------------------------------

    dwm_conf_file = fopen(dwm_conf_filename, "w");
    temp_file = fopen(temp_filename, "r");

    while( fgets(init_line, LINE_SIZE, temp_file) ){
        fprintf(dwm_conf_file, "%s", init_line);
    }

    fclose(temp_file);
    fclose(dwm_conf_file);

    // ----------------------------------------------------------------CLEANUP & MAKE----------------------------------------------------

    system("cd /home/adi/.config/st && sudo make clean install && cd");
    system("cd /home/adi/.config/dwm && sudo make clean install && cd");

    if (remove(temp_filename) == 0){
        printf("\nRemoved temporary file successfully\n");
    } else {
        printf("\nUnable to delete temporary file\n");
    }

    // ----------------------------------------------------------------QUIT DWM----------------------------------------------------

    FILE *fp;
    char cmd_output[64];

    fp = popen("echo -e 'Yes\nNo' | dmenu -p 'Kill DWM?' -fn 'JetBrainsMono NFM:style=Bold:size=28'", "r");

    // Error handling
    if (fp == NULL) {
        printf("Exit Prompt Failed!");
        return -1;
    }

    while (fgets(cmd_output, sizeof(cmd_output), fp) != NULL) {
        if(strcmp(cmd_output, "Yes\n") == 0){
            popen("pkill dwm", "r");
        }
    }

    pclose(fp);


    return 0;
}
