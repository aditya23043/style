target: something

something: src/theme.c
	gcc src/theme.c -o bin/theme

run: bin/theme
	./bin/theme
