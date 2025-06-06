#define BUFFER_SIZE 1024

#define ST_CONFIG_FILE "/home/adi/.config/st/config.h"
#define VIM_CONFIG_FILE "/home/adi/.vimrc"
#define FISH_CONFIG_FILE "/home/adi/.config/fish/config.fish"

#define TEMP_FILE "/home/adi/.config/st/style.tmp"

#define ST_BUILD_CMD "cd /home/adi/.config/st; sudo make clean install; cd"

struct Theme {
    char *name;
    char *vim_name;
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

const struct Theme gruvbox = {
    "Gruvbox", "gruvbox", "dark",    "#282828", "#ebdbb2", "#484848", "#484848",
    "#fb4934", "#b8bb26", "#fabd2f", "#83a598", "#d3869b", "#8ec07c", "#fbf1c7",
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
    "Solarized Dark", "solarized8", "dark",    "#003d4d", "#839496",
    "#002b36",        "#282828",    "#dc322f", "#859900", "#b58900",
    "#268bd2",        "#d33682",    "#2aa198", "#839496",
};

const struct Theme solarized_light = {
    "Solarized Light", "solarized8", "light",   "#fcf0cf", "#576d75",
    "#e6d8b3",         "#282828",    "#dc322f", "#859900", "#b58900",
    "#268bd2",         "#d33682",    "#2aa198", "#839496",
};

const struct Theme onedark = {
    "Onedark", "onedark", "dark",    "#16181d", "#abb2bf", "#2c303a", "#282c34",
    "#e06c75", "#98c379", "#e5c07b", "#61afef", "#c678dd", "#56b6c2", "#c5cad3",
};

const struct Theme tokyonight = {
    "Tokyonight", "tokyonight", "dark",    "#15161e", "#c0caf5",
    "#1f202e",    "#2a2c3c",    "#f7768e", "#9ece6a", "#e0af68",
    "#7aa2f7",    "#bb9af7",    "#7dcfff", "#cbd0e6",
};

const struct Theme okdark = {
    "Ok Colors", "wildcharm", "dark",    "#010102", "#fefcf4",
    "#212126",   "#212126",   "#fe989b", "#24d998", "#e0b316",
    "#5cc6fc",   "#fb8ed5",   "#19d2d7", "#e0ded8",
};

const struct Theme oklight = {
    "Ok Colors Light", "zellner", "light",   "#fefcf4", "#000000",
    "#e0ded8",         "#212126", "#d01a41", "#17865d", "#8b6e09",
    "#0a7caa",         "#c30d97", "#0c8285", "#e0ded8",
};

const struct Theme dracula = {
    "Dracula", "dracula", "dark",    "#16171d", "#F8F8F2", "#282a36", "#282a36",
    "#FF5555", "#50FA7B", "#F1FA8C", "#0a7caa", "#BD93F9", "#8BE9FD", "#F8F8F2",
};

const struct Theme jellybeans = {
    "Jellybeans", "jellybeans", "dark",    "#151515", "#e8e8d3",
    "#353535",    "#3b3b3b",    "#cf6a4c", "#99ad6a", "#d8ad4c",
    "#597bc5",    "#a037b0",    "#71b9f8", "#adadad",
};

const struct Theme rosepine = {
    "Rosepine", "rosepine", "dark",    "#000000", "#e0def4",
    "#232323",  "#1f1d2e",  "#eb6f92", "#a9b665", "#f6c177",
    "#31748f",  "#c4a7e7",  "#9ccfd8", "#ffffff",
};

const struct Theme codedark = {
    "CodeDark", "codedark", "dark",    "#1e1e1e", "#d4d4d4",
    "#3e3e3e",  "#3e3e3e",  "#D16969", "#ebbcba", "#D7BA7D",
    "#569CD6",  "#C586C0",  "#9CDCFE", "#d4d4d4",
};

const struct Theme catppuccin_mocha = {
    "Catppuccin Mocha", "catppuccin_mocha", "dark",    "#1e1e2e", "#cdd6f4",
    "#32324d",          "#28283e",          "#F38BA8", "#A6E3A1", "#F9E2AF",
    "#89B4FA",          "#CBA6F7",          "#94E2D5", "#a6adc8",
};

const struct Theme quiet_dark = {
    "Quiet Dark", "quiet",   "dark",    "#000000", "#c7c7c7",
    "#232323",    "#33384d", "#c7c7c7", "#c7c7c7", "#c7c7c7",
    "#c7c7c7",    "#c7c7c7", "#c7c7c7", "#c7c7c7",
};

const struct Theme moonfly = {
    "Moonfly", "moonfly", "dark",    "#080808", "#c6c6c6", "#282828", "#282828",
    "#ff5454", "#8cc85f", "#e3c78a", "#80a0ff", "#d183e8", "#79dac8", "#a1aab8",
};

const struct Theme iceberg = {
    "Iceberg", "iceberg", "dark",    "#161821", "#c7c7c7", "#33384d", "#33384d",
    "#e27878", "#b4be82", "#e4aa80", "#84a0c6", "#a093c7", "#89b8c2", "#c6c8d1",
};

const struct Theme github_dark = {
    "GitHub Dark", "wildcharm", "dark",    "#000000", "#ecf2f7",
    "#232323",     "#121212",   "#fa7970", "#7ce38b", "#faa356",
    "#77bdfb",     "#cea5fb",   "#a2d2fb", "#c6cdd5",
};

struct Theme themes[] = {
    gruvbox,
    gruvbox_material_dark,
    gruvbox_material_light,
    solarized_dark,
    solarized_light,
    onedark,
    tokyonight,
    okdark,
    oklight,
    dracula,
    jellybeans,
    rosepine,
    codedark,
    catppuccin_mocha,
    quiet_dark,
    moonfly,
    iceberg,
    github_dark,
};

int patch_st(int index);
int patch_vim(int index);
int patch_fish(int index);
