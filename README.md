# Minesweeper
A minesweeper game written in C using [SDL](https://www.libsdl.org/). The purpose of this game was to practise building small projects.

## Usage
For custom settings:
```
./Minesweeper <board_width> <board_height> <numer_of_mines>
```
For extra information:
```
./Minesweeper ?
```
## Building on Windows using `gcc`, `git` and `cmake`
### Prerequisites:
This guide assumes you have these installed on your machine: 
- [MinGW](https://www.mingw-w64.org/downloads/) 
- [CMake](https://cmake.org/) 
- [Git](https://git-scm.com/)

### Build instructions:

```powershell
$ git clone https://github.com/LionasBaslis2sis/Minesweeper.git
```
To build this project you will first need to download the latest [SDL developement library](https://www.libsdl.org/download-2.0.php) (be sure to download the one with "-VC" extension)
- extract it and rename the folder to `SDL2`
- go to `/Minesweeper/` and create a new folder `libs`
- move `SDL2` to `libs` 

Now, from `/Minesweeper/` directory and run these commands:
```powershell
$ cmake -D CMAKE_C_COMPILER=<path_to_gcc> -G "MinGW Makefiles" -S . -B <build_dir>
$ cd <build_dir>
$ mingw32-make
```
And finally from `libs/SDL2/lib/x64`(or `x86`) copy `SDL2.dll` to your build directory.