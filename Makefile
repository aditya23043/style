theme: src/theme.c
	gcc src/theme.c -o bin/theme

font: src/fonts.c
	gcc src/fonts.c -o bin/font -lncurses

run: bin/theme
	./bin/theme
