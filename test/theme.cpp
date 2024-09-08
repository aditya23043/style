#include <stdlib.h>
#include <iostream>

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

struct _color {
	std::string desc;
	std::string hex;
};

class palette {
public:

	int size;
	std::string theme;
	_color* arr;

	palette(std::string theme){
		this->theme = theme;
		this->size = 0;
		this->arr = new _color[size];
	}

	void add(std::string desc, std::string hex){
		_color temp[size];
		for( int i = 0; i < size; i++ ){
			temp[i] = this->arr[i];
		}
		delete[] arr;
		arr = new _color[size+1];
		for( int i = 0; i < size; i++ ){
			arr[i] = temp[i];
		}
		_color foo = { desc, hex };
		arr[size] = foo;
		size++;
	}

	void print(){
		printf("\n");
		printf("{\n");
		for( int i = 0; i < size; i++ ){
			std::cout << "\t" << arr[i].desc << " : " << arr[i].hex << "\n";
		}
		printf("{\n");
		printf("\n");
	}

	std::string get(std::string desc){
		for( int i = 0; i < size; i++ ){
			if( arr[i].desc == desc ){
				return arr[i].hex;
			}
		}
		return "-1";
	}

	~palette(){
		delete[] arr;
	}

};

int main(){

	printf("\nTHEMES\n\n  1. Gruvbox Dark\n  2. Gruvbox Light\n  3. Solarized Dark\n  4. Solarized Light\n\n");
	printf("Choose a theme: ");
	char choice = getchar();


	switch(choice){
		case '1':
			// Gruvbox Dark
			break;
		case '2':
			// Gruvbox Light
			break;
		case '3':
			// Solarized Dark
			break;
		case '4':
			// Solarized Light
			break;
		default:
			printf("\nPick your theme from the following:\n\n  Gruvbox Light\n  Gruvbox Dark\n  Solarized Dark\n  Solarized Light\n");
	}

	palette something("solarized");
	something.print();
	something.add("bg", "#141617");
	something.add("fg", "#ffffff");
	something.print();
	std::cout << something.get("fg") << std::endl;

	return 0;
}
