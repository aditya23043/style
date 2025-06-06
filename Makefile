target: something
	
something: src/theme.c src/fonts.c
	gcc src/theme.c -o bin/theme -lncurses
	gcc src/fonts.c -o bin/font -lncurses

run: bin/theme
	./bin/theme
