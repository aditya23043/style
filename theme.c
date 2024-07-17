#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

/*
 * String methods
 * strlen : length of the string
 * strcat : concatenate first str with the second one onto the first string
 * strcmp : returns 0 if both the arg strings are same
 */

/*
 * Char method from <ctype.h>
 * isalnum : alphanumeric
 * isalpha : alphabetic
 * iscntrl : control character
 * isdigit : digit
 * islower : lowercase
 * isgraph : graphical
 * isprint : printing
 * ispunct : punctuation
 * isspace : space char
 * isupper : uppercase
 * isxdigit: hexadecimal numeric
 *
 * tolower : converts to lowercase
 * toupper : converts to uppercase
 */

/*
 * Stuff to change:
 * 1. neovim
 * 2. dwm
 * 3. st
 * 4. dmenu
 * 5. dunst
 * 6. GTK
 * 7. keyboard color (optional)
 * 8. wallpaper
 */

struct _palette {

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

	printf("\nTHEMES\n\n  1. Gruvbox Dark\n  2. Gruvbox Light\n  3. Solarized Dark\n  4. Solarized Light\n  5. Onedark Dark\n  6. Tokyonight Dark\n\n");
	printf("Choose a theme: ");
	int choice;
	scanf("%d", &choice);

	struct _palette palette;

	switch(choice){
		case 1:
			// Gruvbox Dark
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
			palette.fg = "#654735";
			palette.suggestion = "#e0c685";
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
			palette.fg = "#fdf6e3";
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
			palette.fg = "#002b36";
			palette.suggestion = "#fae8b7";
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

		default:
			printf("\nPick your theme from the following:\n\n  Gruvbox Light\n  Gruvbox Dark\n  Solarized Dark\n  Solarized Light\n");
			return 1;
	}

	regex_t theme_regex;
	int theme_regex_value;

	char finalString[100000] = "";

	theme_regex_value = regcomp(&theme_regex, "static const char .colorname", 0);

	char string[512];
	FILE *foo = fopen("/home/adi/.config/st/config.h", "r");

	while(fgets(string, 512, foo) != NULL){

		theme_regex_value = regexec(&theme_regex, string, 0,  NULL, 0);

		if (theme_regex_value == 0){
			strcat(finalString, "static const char *colorname[] = { \"");
			strcat(finalString, palette.black);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.red);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.green);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.yellow);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.blue);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.magenta);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.cyan);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.white);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.black);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.red);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.green);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.yellow);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.blue);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.magenta);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.cyan);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.white);
			strcat(finalString, "\", ");
			strcat(finalString, "[255] = 0, \"");
			strcat(finalString, palette.fg);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.bg);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.fg);
			strcat(finalString, "\", \"");
			strcat(finalString, palette.bg);
			strcat(finalString, "\" };\n");
		} else{
			strcat(finalString, string);
		}

	}

	fclose(foo);

	foo = fopen("/home/adi/.config/st/config.h", "w");
	fprintf(foo, "%s", finalString);
	fclose(foo);

	// FISH AUTOSUGGESTION COLOR
	strcpy(finalString, "");
	regex_t fish_color_regex;
	int fish_color_regex_value = regcomp(&fish_color_regex, "set -U fish_color_autosuggestion", 0);

	foo = fopen("/home/adi/.config/fish/config.fish", "r");
	while(fgets(string, 512, foo) != NULL){
		fish_color_regex_value = regexec(&fish_color_regex, string, 0,  NULL, 0);
		if (fish_color_regex_value == 0){
			strcat(finalString, "set -U fish_color_autosuggestion \"");
			strcat(finalString, palette.suggestion);
			strcat(finalString, "\"");
		} else{
			strcat(finalString, string);
		}
	}
	fclose(foo);

	foo = fopen("/home/adi/.config/fish/config.fish", "w");
	fprintf(foo, "%s", finalString);
	fclose(foo);

	system("cd /home/adi/.config/st && sudo make clean install && cd");

	return 0;
}
