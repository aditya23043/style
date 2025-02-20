# Demo


https://github.com/user-attachments/assets/10a0abfe-3de8-46a6-a86f-0e45a4d28791




# Purpose
- Used in order to efficiently synchronize theming and fonts across all my development tools like...
    - vim
    - dwm
    - st
    - fish shell
    - dunst
    - neovim
    - gtk
    - wallpaper

> NOTE: This project is still work in progress

# Dependencies
- C compiler; like gcc / clang / etc.
- ncurses
- make (optional)

# How to run?
- Clone the repository to your local system
```
git clone https://github/aditya23043/style
```
- Build the binary using `make`
```
cd style
make font
make theme
```
- Run the suitable binary
```
<repo>/bin/theme
OR
<repo>/bin/font
...
```

# Dev Log
## Theme Switcher
- Still a work in progress as of `2025-02-20 23:03`
- As of now, I am able to switch vim's color scheme effectively while also looking for basic errors like absence of vim binary or existence of vim's configuration file and the program is intended to be "responsive", i.e. it should work on anyone's system without failing and without having to tweak anything in the source code

## Font Switcher
- It is almost done as of `2025-02-20 23:05`
- I just have to add all the fonts I use in the `init_fonts()` function and also I might have to add some error checking so that it can be run on anyone's system without failing
