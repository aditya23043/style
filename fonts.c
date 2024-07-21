#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

int main(int argc, char *argv[])
{

	printf("\nFONTS:\n    1. Victor\n    2. JetBrains\n    3. Iosevka\n    4. Pragmasevka\n    5. Blex\n    6. IBM Plex\n    7. Lekton\n    8. Nanum Gothic Coding\n    9. Ubuntu\n    10. Iosevka SS14\n    11. Fira Code\n    12. Sarasa Gothic\n    13. Recursive Mono\n\nEnter: ");
	int choice;
	scanf("%d", &choice);

	char *fontFamily;
	char *fontStyle;
	char *fontSize;
	char *fontSpacing;

	switch (choice) {

		case 1:
			fontFamily = "VictorMono NFM";
			fontStyle = "Bold";
			fontSize = "18";
			fontSpacing = "0.95";
			break;

		case 2:
			fontFamily = "JetBrainsMonoNFM";
			fontStyle = "Bold";
			fontSize = "16";
			fontSpacing = "0.9";
			break;

		case 3:
			fontFamily = "Iosevka NFM";
			fontStyle = "Regular";
			fontSize = "26";
			fontSpacing = "1.0";
			break;

		case 4:
			fontFamily = "Pragmasevka Nerd Font:";
			fontStyle = "Regular";
			fontSize = "24";
			fontSpacing = "0.9";
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
			fontFamily = "Ubuntu Mono";
			fontStyle = "Bold";
			fontSize = "21";
			fontSpacing = "0.95";
			break;

		case 10:
			fontFamily = "Iosevka Term SS14";
			fontStyle = "Regular";
			fontSize = "26";
			fontSpacing = "1.0";
			break;

		case 11:
			fontFamily = "Fira Code";
			fontStyle = "Medium";
			fontSize = "20";
			fontSpacing = "0.9";
			break;

		case 12:
			fontFamily = "Sarasa Mono CL";
			fontStyle = "Regular";
			fontSize = "24";
			fontSpacing = "1.0";
			break;

		case 13:
			fontFamily = "RecMonoLinear Nerd Font Mono";
			fontStyle = "Regular";
			fontSize = "18";
			fontSpacing = "0.9";
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
