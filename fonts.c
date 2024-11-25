#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

int main(int argc, char *argv[])
{
    long choice;

    if(argv[1]){
        choice = strtol(argv[1], NULL, 10);
        printf("%ld", choice);
    } else {
        printf("\nFONTS:\n    0. Install All Listed Fonts\n    1. Victor\n    2. JetBrains\n    3. Iosevka\n    4. Pragmasevka\n    5. Blex\n    6. IBM Plex\n    7. Lekton\n    8. Nanum Gothic Coding\n    9. Ubuntu\n    10. Fira Code\n    11. Sarasa Gothic\n    12. Recursive Mono\n    13. Inconsolata\n    14. Share Tech\n    15. Reddit Mono\n    16. Monoid\n    17. Fantasque\n    18. Input\n    19. Monoisome\n    20. Martian\n    21. Caskaydia Cove\n    22. SF Mono\n    23. Hack\n    24. ZedMono\n    25. CommitMono\n    26. SauceCodePro\n    27. SpaceMono\n    28. Meslo LGL DZ\n    29. Meslo LGS DZ\n    30. Agave\n\nEnter: ");
        scanf("%ld", &choice);
    }

    char *fontFamily;
    char *fontStyle;
    char *fontSize;
    char *fontSpacing;

    switch (choice) {

        case 0:
            // NOT INSTALLED -> Reddit Mono
            system("sudo pacman -S --noconfirm --needed ttf-victor-mono-nerd ttf-jetbrains-mono-nerd ttc-iosevka ttf-ibmplex-mono-nerd ttf-lekton-nerd ttf-ubuntu-font-family ttf-fira-code ttf-sarasa-gothic ttf-recursive-nerd ttf-inconsolata-nerd ttf-sharetech-mono-nerd ttf-monoid-nerd ttf-fira-code ttf-fantasque-sans-mono ttf-input ttf-martian-mono-nerd ttf-cascadia-code-nerd ttf-ibm-plex ttf-hack-nerd");
            system("cd /home/adi/AUR && git clone https://aur.archlinux.org/ttf-pragmasevka-nerd-font && cd ttf-pragmasevka-nerd-font && makepkg -si && cd");
            system("cd /home/adi/AUR && git clone https://aur.archlinux.org/ttf-nanumgothic_coding && cd ttf-nanumgothic_coding && makepkg -si && cd");
            system("cd /home/adi/AUR && git clone https://aur.archlinux.org/otf-apple-fonts && cd otf-apple-fonts && makepkg -si && cd");
            break;

        case 1:
            fontFamily = "VictorMono NFP";
            fontStyle = "Bold";
            fontSize = "18";
            fontSpacing = "1.0";
            break;

        case 2:
            fontFamily = "JetBrainsMonoNFM";
            fontStyle = "ExtraBold";
            fontSize = "14";
            fontSpacing = "1.0";
            break;

        case 3:
            fontFamily = "Iosevka";
            fontStyle = "Bold";
            fontSize = "20";
            fontSpacing = "1.0";
            break;

        case 4:
            fontFamily = "Pragmasevka Nerd Font";
            fontStyle = "Regular";
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
            fontStyle = "Regular";
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
            fontSize = "17";
            fontSpacing = "1.0";
            break;

        case 9:
            fontFamily = "Ubuntu Mono";
            fontStyle = "SemiBold";
            fontSize = "20";
            fontSpacing = "1.0";
            break;

        case 10:
            fontFamily = "Fira Mono";
            fontStyle = "Medium";
            fontSize = "13";
            fontSpacing = "1.0";
            break;

        case 11:
            fontFamily = "Sarasa Mono CL";
            fontStyle = "Bold";
            fontSize = "19";
            fontSpacing = "0.9";
            break;

        case 12:
            fontFamily = "RecMonoLinear Nerd Font Mono";
            fontStyle = "Regular";
            fontSize = "18";
            fontSpacing = "0.9";
            break;

        case 13:
            fontFamily = "Inconsolata Nerd Font";
            fontStyle = "Regular";
            fontSize = "20";
            fontSpacing = "0.95";
            break;

        case 14:
            fontFamily = "ShureTechMono Nerd Font Mono";
            fontStyle = "Regular";
            fontSize = "18";
            fontSpacing = "0.85";
            break;

        case 15:
            fontFamily = "Reddit Mono";
            fontStyle = "Medium";
            fontSize = "17";
            fontSpacing = "0.85";
            break;

        case 16:
            fontFamily = "Monoid";
            fontStyle = "Retina";
            fontSize = "18";
            fontSpacing = "0.95";
            break;

        case 17:
            fontFamily = "Fantasque Sans Mono";
            fontStyle = "Bold";
            fontSize = "15";
            fontSpacing = "1.0";
            break;

        case 18:
            fontFamily = "Input Mono Narrow";
            fontStyle = "Regular";
            fontSize = "18";
            fontSpacing = "0.9";
            break;

        case 19:
            fontFamily = "Monoisome";
            fontStyle = "Bold";
            fontSize = "14";
            fontSpacing = "1.0";
            break;

        case 20:
            fontFamily = "MartianMono NFM";
            fontStyle = "Condensed Regular";
            fontSize = "17";
            fontSpacing = "0.85";
            break;

        case 21:
            fontFamily = "CaskaydiaCove NFM";
            fontStyle = "Bold";
            fontSize = "14";
            fontSpacing = "0.85";
            break;

        case 22:
            fontFamily = "SF Mono";
            fontStyle = "Bold";
            fontSize = "13";
            fontSpacing = "0.85";
            break;

        case 23:
            fontFamily = "Hack Nerd Font Mono";
            fontStyle = "Bold";
            fontSize = "13";
            fontSpacing = "1.0";
            break;

        case 24:
            fontFamily = "ZedMono Nerd Font Mono";
            fontStyle = "Bold";
            fontSize = "14";
            fontSpacing = "0.9";
            break;

        case 25:
            fontFamily = "CommitMono Nerd Font Mono";
            fontStyle = "Bold";
            fontSize = "14";
            fontSpacing = "0.9";
            break;

        case 26:
            fontFamily = "SauceCodePro Nerd Font Mono";
            fontStyle = "Bold";
            fontSize = "14";
            fontSpacing = "0.9";
            break;

        case 27:
            fontFamily = "SpaceMono Nerd Font Mono";
            fontStyle = "Bold";
            fontSize = "14";
            fontSpacing = "0.9";
            break;

        case 28:
            fontFamily = "MesloLGLDZ Nerd Font Mono";
            fontStyle = "Bold";
            fontSize = "15";
            fontSpacing = "0.9";
            break;

        case 29:
            fontFamily = "MesloLGSDZ Nerd Font Mono";
            fontStyle = "Bold";
            fontSize = "15";
            fontSpacing = "0.9";
            break;

        case 30:
            fontFamily = "Agave Nerd Font Mono";
            fontStyle = "Bold";
            fontSize = "15";
            fontSpacing = "1.0";
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
