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

};

int main(){

	// ----------------------------------------------------------------DEFINING STUFF----------------------------------------------------------------

	char *st_conf_filename = "/home/adi/.config/st/config.h";
	char *fish_conf_filename = "/home/adi/.config/fish/config.fish";
	char *nvim_conf_filename = "/home/adi/.config/nvim/init.lua";
	char *temp_filename = "temp.h";

	const int LINE_SIZE = 512;

	char init_line[LINE_SIZE];
	char final_line[LINE_SIZE];

	regex_t regex;
	int regex_value;

	regex_t regex_2;
	int regex_2_value;

	FILE *st_conf_file;
	FILE *fish_conf_file;
	FILE *nvim_conf_file;
	FILE *temp_file;

	// ----------------------------------------------------------------INPUT PROMPT-----------------------------------------------------------------

	printf("\nTHEMES\n\n  1. Gruvbox Dark\n  2. Gruvbox Light\n  3. Solarized Dark\n  4. Solarized Light\n  5. Onedark Dark\n  6. Tokyonight Dark\n  7. CUSTOM\n  8. CUSTOM 2\n  9. ok colors\n\n");
	printf("Choose a theme: ");
	int choice;
	scanf("%d", &choice);

	// ----------------------------------------------------------------SETTING PALETTE--------------------------------------------------------------

	struct _palette palette;

	switch(choice){
		case 1:
			// Gruvbox Dark
			strcpy(palette.nvim_colorscheme, "gruvbox-material");
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
			break;
		case 2:
			// Gruvbox Light
			strcpy(palette.nvim_colorscheme, "gruvbox-material");
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
			break;
		case 3:
			// Solarized Dark
			strcpy(palette.nvim_colorscheme, "solarized");
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
			break;
		case 4:
			// Solarized Light
			strcpy(palette.nvim_colorscheme, "solarized");
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
			break;
		case 5:
			// Onedark
			strcpy(palette.nvim_colorscheme, "onedark");
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
			break;
		case 6:
			// Tokyonight
			strcpy(palette.nvim_colorscheme, "tokyonight-storm");
			palette.nvim_background = "dark";
			palette.fg = "#a9b1d6";
			palette.suggestion = "#2a2c3c";
			palette.bg = "#15161e";
	        palette.black = "#2a2c3c";
	        palette.red = "#f7768e";
	        palette.green = "#9ece6a";
	        palette.yellow = "#e0af68";
	        palette.blue = "#7aa2f7";
	        palette.magenta = "#bb9af7";
	        palette.cyan = "#7dcfff";
	        palette.white = "#cbd0e6";
			break;
		case 7:
			// CUSTOM
			strcpy(palette.nvim_colorscheme, "tokyonight-night");
			palette.nvim_background = "dark";
			palette.fg = "#cdd6f4";
			palette.suggestion = "#1f1f1f";
			palette.bg = "#0a0a0a";
	        palette.black = "#2a2c3c";
	        palette.red = "#f7768e";
	        palette.green = "#9ece6a";
	        palette.yellow = "#e0af68";
	        palette.blue = "#7aa2f7";
	        palette.magenta = "#bb9af7";
			// palette.cyan = "#99f6e4";  
	        palette.cyan = "#7dcfff";
			palette.white = "#cdd6f4";  
			break;
		case 8:
			// CUSTOM 2
			strcpy(palette.nvim_colorscheme, "gruvbox-material");
			palette.nvim_background = "dark";
			palette.fg = "#ddc7a1";
			palette.suggestion = "#242729";
			palette.bg = "#000000";
			palette.black = "#282828";
			palette.red = "#ea6962";
			palette.green = "#a9b665";
			palette.yellow = "#6600ff";
			palette.blue = "#7daea3";
			palette.magenta = "#d8a657";
			palette.cyan = "#89b482";
			palette.white = "#d4be98";
			break;

    case 9:
			// OK COLORS
			strcpy(palette.nvim_colorscheme, "okcolors-sharp");
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
			strncat(final_line, "\"", sizeof("\""));
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

	regex_value = regcomp(&regex, "vim.cmd.colorscheme", 0);
	regex_2_value = regcomp(&regex_2, "vim.opt.background", 0);

	nvim_conf_file = fopen(nvim_conf_filename, "r");
	temp_file = fopen(temp_filename, "w");

	while( fgets(init_line, LINE_SIZE, nvim_conf_file) ){
		regex_value = regexec(&regex, init_line, 0,  NULL, 0);
		regex_2_value = regexec(&regex_2, init_line, 0,  NULL, 0);

		if (regex_value == 0){
			strncpy(final_line, "vim.cmd.colorscheme \"", sizeof("vim.cmd.colorscheme \""));
			strncat(final_line, palette.nvim_colorscheme, sizeof(palette.nvim_colorscheme));
			strncat(final_line, "\"\n", sizeof("\"\n"));
		} else if (regex_2_value == 0){
			strncpy(final_line, "vim.opt.background = \"", sizeof("vim.opt.background = \""));
			strncat(final_line, palette.nvim_background, sizeof(palette.nvim_background));
			strncat(final_line, "\"\n", sizeof("\"\n"));
		} else {
			strncpy(final_line, init_line, sizeof(init_line));
		}
		
		fprintf(temp_file, "%s", final_line);
	}

	fclose(temp_file);
	fclose(nvim_conf_file);

	// ----------------------------------------------------------------TEMP -> FINAL----------------------------------------------------------------

	nvim_conf_file = fopen(nvim_conf_filename, "w");
	temp_file = fopen(temp_filename, "r");

	while( fgets(init_line, LINE_SIZE, temp_file) ){
		fprintf(nvim_conf_file, "%s", init_line);
	}

	fclose(temp_file);
	fclose(nvim_conf_file);

	// ----------------------------------------------------------------CLEANUP & MAKE----------------------------------------------------

	system("cd /home/adi/.config/st && sudo make clean install && cd");

	if (remove(temp_filename) == 0){
		printf("\nRemoved temporary file successfully\n");
	} else {
		printf("\nUnable to delete temporary file\n");
	}

	return 0;
}
