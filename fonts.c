#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

int main(int argc, char *argv[])
{

	printf("\nFONTS:\n    1. Victor\n    2. JetBrains\n    3. Iosevka\n    4. Pragmasevka\n    5. Blex\n    6. IBM Plex\n    7. Lekton\n    8. Nanum Gothic Coding\n    9. Ubuntu\n    10. Iosevka SS14\n    11. Fira Code\n    12. Sarasa Gothic\n    13. Recursive Mono\n    14. Inconsolata\n    15. Share Tech\n    16. Reddit Mono\n    17. Monoid\n    18. Fira Code\n    19. Fantasque\n    20. Input\n    21. Monoisome\n    22. Martian\n    23. Caskaydia Cove\n\nEnter: ");
	long choice;
	scanf("%ld", &choice);

	char *fontFamily;
	char *fontStyle;
	char *fontSize;
	char *fontSpacing;

	switch (choice) {

		case 1:
			fontFamily = "VictorMono NFM";
			fontStyle = "Bold";
			fontSize = "20";
			fontSpacing = "0.9";
			break;

		case 2:
			fontFamily = "JetBrainsMonoNFM";
			fontStyle = "Bold";
			// fontSize = "15";
			// fontSize = "12";
			fontSize = "18";
			fontSpacing = "0.9";
			break;

		case 3:
			fontFamily = "Iosevka NFM";
			fontStyle = "Regular";
			fontSize = "20";
			fontSpacing = "0.85";
			break;

		case 4:
			fontFamily = "Pragmasevka:";
			fontStyle = "Bold";
			fontSize = "20";
			fontSpacing = "1.0";
			break;

		case 5:
			fontFamily = "BlexMono NFM";
			fontStyle = "Bold";
			fontSize = "18";
			fontSpacing = "0.9";
			break;

		case 6:
			fontFamily = "IBM Plex Mono";
			fontStyle = "Semibold";
			fontSize = "18";
			fontSpacing = "0.9";
			break;

		case 7:
			fontFamily = "Lekton Nerd Font Mono";
			fontStyle = "Bold";
			fontSize = "21";
			fontSpacing = "0.9";
			break;

		case 8:
			fontFamily = "Nanum Gothic Coding";
			fontStyle = "Bold";
			fontSize = "18";
			fontSpacing = "1.0";
			break;

		case 9:
			fontFamily = "UbuntuMono Nerd Font Mono";
			fontStyle = "Medium";
			fontSize = "17";
			fontSpacing = "0.9";
			break;

		case 10:
			fontFamily = "Iosevka Term SS14";
			fontStyle = "Bold";
			fontSize = "20";
			fontSpacing = "0.85";
			break;

		case 11:
			fontFamily = "Fira Code";
			fontStyle = "Medium";
			fontSize = "16";
			fontSpacing = "0.9";
			break;

		case 12:
			fontFamily = "Sarasa Mono CL";
			fontStyle = "Bold";
			fontSize = "20";
			fontSpacing = "0.9";
			break;

		case 13:
			fontFamily = "RecMonoLinear Nerd Font Mono";
			fontStyle = "Regular";
			fontSize = "18";
			fontSpacing = "0.9";
			break;

		case 14:
			fontFamily = "Inconsolata Nerd Font";
			fontStyle = "Bold";
			fontSize = "20";
			fontSpacing = "0.9";
			break;

		case 15:
			fontFamily = "ShureTechMono Nerd Font Mono";
			fontStyle = "Bold";
			fontSize = "20";
			fontSpacing = "0.9";
			break;

		case 16:
			fontFamily = "Reddit Mono";
			fontStyle = "Semibold";
			fontSize = "17";
			fontSpacing = "0.8";
			break;

		case 17:
			fontFamily = "Monoid";
			fontStyle = "Retina";
			fontSize = "18";
			fontSpacing = "0.95";
			break;

		case 18:
			fontFamily = "Fira Code";
			fontStyle = "Retina";
			fontSize = "20";
			fontSpacing = "0.9";
			break;

		case 19:
			fontFamily = "Fantasque Sans Mono";
			fontStyle = "Regular";
			fontSize = "20";
			fontSpacing = "0.9";
			break;

		case 20:
			fontFamily = "Input Mono Narrow";
			fontStyle = "Bold";
			fontSize = "18";
			fontSpacing = "0.9";
			break;

		case 21:
			fontFamily = "Monoisome";
			fontStyle = "Bold";
			fontSize = "14";
			fontSpacing = "1.0";
			break;

		case 22:
			fontFamily = "MartianMono NFM";
			fontStyle = "Condensed Medium";
			fontSize = "18";
			fontSpacing = "0.9";
			break;

		case 23:
			fontFamily = "CaskaydiaCove NFM";
			fontStyle = "Medium";
			fontSize = "17";
			fontSpacing = "0.85";
			break;

		default:
			printf("Invalid option! Try Again!\n");
			return 1;
	}

	regex_t font_regex;
	int font_regex_value;

	regex_t spacing_regex;
	int spacing_regex_value;

	char finalString[100000] = "";


	font_regex_value = regcomp(&font_regex, "static char .font =", 0);
	spacing_regex_value = regcomp(&spacing_regex, "static float cwscale =", 0);

	char string[256];
	FILE *foo = fopen("/home/adi/.config/st/config.h", "r");

	while(fgets(string, 256, foo) != NULL){

		font_regex_value = regexec(&font_regex, string, 0,  NULL, 0);
		spacing_regex_value = regexec(&spacing_regex, string, 0,  NULL, 0);

		if (spacing_regex_value == 0){
			strcat(finalString, "static float cwscale = ");
			strcat(finalString, fontSpacing);
			strcat(finalString, ";\n");
			
		} else if (font_regex_value == 0){
			strcat(finalString, "static char *font = \"");
			strcat(finalString, fontFamily);
			strcat(finalString, ":style=");
			strcat(finalString, fontStyle);
			strcat(finalString, ":size=");
			strcat(finalString, fontSize);
			strcat(finalString, ":antialias=true:autohint=true\";\n");
		} else{
			strcat(finalString, string);
		}

	}
	// printf("%s\n", finalString);

	fclose(foo);

	foo = fopen("/home/adi/.config/st/config.h", "w");
	fprintf(foo, "%s", finalString);
	fclose(foo);

	system("cd /home/adi/.config/st && sudo make clean install && cd");

	return 0;
}
