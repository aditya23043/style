#include <ncurses.h>
#include <stdio.h>

char colorschemes[][18] = {

    {
        "Gruvbox", "gruvbox", "dark",
        "#ebdbb2", // fg
        "#484848", // fg_disabled
        "#282828", // bg
        "#484848", // black
        "#fb4934", // red
        "#b8bb26", // green
        "#fabd2f", // yellow
        "#83a598", // blue
        "#d3869b", // magenta
        "#8ec07c", // cyan
        "#fbf1c7", // white
        "#000000", // dwm_sel_fg
        "#888888", // dwm_norm_fg
        "#282828", // dwm_norm_bg
        "#83a598", // dwm_sel_bg
    },

    {"Gruvbox Dark", "gruvbox-material", "dark", "#ddc7a1", "#242729",
     "#141617", "#282828", "#ea6962", "#a9b665", "#d8a657", "#7daea3",
     "#d3869b", "#89b482", "#d4be98", "#000000", "#888888", "#282828",
     "#7daea3"},

    {"Gruvbox Light"
     "gruvbox-material",
     "light", "#654735", "#dfcd9f", "#ebdbb2", "#282828", "#c14a4a", "#6c782e",
     "#b47109", "#45707a", "#945e80", "#4c7a5d", "#dbddbf", "#000000",
     "#888888", "#ebdbb2", "#c14a4a"},

    {"Solarized Dark", "solarized8", "dark", "#839496", "#003d4d", "#002b36",
     "#282828", "#dc322f", "#859900", "#b58900", "#268bd2", "#d33682",
     "#2aa198", "#839496", "#000000", "#888888", "#002b36", "#2aa198"},

    {"Solarized Light", "solarized8", "light", "#576d75", "#e6d8b3", "#fcf0cf",
     "#282828", "#dc322f", "#859900", "#b58900", "#268bd2", "#d33682",
     "#2aa198", "#839496", "#000000", "#888888", "#fcf0cf", "#2aa198"},

    {"Onedark Dark", "onedark", "dark", "#abb2bf", "#2c303a", "#16181d",
     "#282c34", "#e06c75", "#98c379", "#e5c07b", "#61afef", "#c678dd",
     "#56b6c2", "#c5cad3", "#000000", "#888888", "#16181d", "#e06c75"},

    {"Tokyonight", "tokyonight", "dark", "#c0caf5", "#1f202e", "#15161e",
     "#2a2c3c", "#f7768e", "#9ece6a", "#e0af68", "#7aa2f7", "#bb9af7",
     "#7dcfff", "#cbd0e6", "#000000", "#888888", "#15161e", "#7aa2f7"},

    {"Ok Colors", "okcolors-sharp", "dark", "#fefcf4", "#212126", "#010102",
     "#212126", "#fe989b", "#24d998", "#e0b316", "#5cc6fc", "#fb8ed5",
     "#19d2d7", "#e0ded8", "#000000", "#888888", "#010102", "#24d998"},

    {"Ok Colors Light", "okcolors-sharp", "light", "#000000", "#e0ded8",
     "#fefcf4", "#212126", "#d01a41", "#17865d", "#8b6e09", "#0a7caa",
     "#c30d97", "#0c8285", "#e0ded8", "#000000",
     "#888888"
     "#fefcf4",
     "#d01a41"},

    {"Dracula", "dracula", "dark", "#F8F8F2", "#282a36", "#16171d", "#282a36",
     "#FF5555", "#50FA7B", "#F1FA8C", "#0a7caa", "#BD93F9", "#8BE9FD",
     "#F8F8F2", "#000000", "#888888", "#16171d", "#BD93F9"},

    {"Jellybeans", "jellybeans", "dark", "#e8e8d3", "#353535", "#151515",
     "#3b3b3b", "#cf6a4c", "#99ad6a", "#d8ad4c", "#597bc5", "#a037b0",
     "#71b9f8", "#adadad", "#000000", "#888888", "#151515", "#cf6a4c"},

    {"Github Dark", "ghdark", "dark", "#ecf2f7", "#232323", "#000000",
     "#121212", "#fa7970", "#7ce38b", "#faa356", "#77bdfb", "#cea5fb",
     "#a2d2fb", "#c6cdd5", "#000000", "#888888", "#000000", "#fa7970"},

    {"Iceberg", "iceberg", "dark", "#c7c7c7", "#33384d", "#161821", "#33384d",
     "#e27878", "#b4be82", "#e4aa80", "#84a0c6", "#a093c7", "#89b8c2",
     "#c6c8d1", "#161821", "#888888", "#161821", "#84a0c6"},

    {"Moonfly", "moonfly", "dark", "#c6c6c6", "#282828", "#080808", "#282828",
     "#ff5454", "#8cc85f", "#e3c78a", "#80a0ff", "#d183e8", "#79dac8",
     "#a1aab8", "#000000", "#888888", "#080808", "#d183e8"},

    {"Quiet", "quiet", "dark", "#c7c7c7", "#232323", "#000000", "#33384d",
     "#c7c7c7", "#c7c7c7", "#c7c7c7", "#c7c7c7", "#c7c7c7", "#c7c7c7",
     "#c7c7c7", "#161821", "#888888", "#000000", "#c7c7c7"},

    {"Catppuccin", "catppuccin_mocha", "dark", "#cdd6f4", "#32324d", "#1e1e2e",
     "#28283e", "#F38BA8", "#A6E3A1", "#F9E2AF", "#89B4FA", "#CBA6F7",
     "#94E2D5", "#a6adc8", "#000000", "#888888", "#1e1e2e", "#CBA6F7"},

    {"Code Dark"
     "codedark",
     "dark", "#d4d4d4", "#3e3e3e", "#1e1e1e", "#3e3e3e", "#D16969", "#ebbcba",
     "#D7BA7D", "#569CD6", "#C586C0", "#9CDCFE", "#d4d4d4", "#000000",
     "#888888", "#1e1e1e", "#569CD6"},

    {"Rose Pine", "rosepine", "dark", "#e0def4", "#232323", "#000000",
     "#1f1d2e", "#eb6f92", "#a9b665", "#f6c177", "#31748f", "#c4a7e7",
     "#9ccfd8", "#ffffff", "#000000", "#888888", "#000000", "#c4a7e7"},

};

int main(int argc, char **arv) {

    initscr();
    noecho();

    printw("something bruh idk");

    getch();

    endwin();

    return 0;
}
