cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(Minesweeper VERSION 1.0)

file(GLOB SOURCE "src/*.c" "include/*.h")
# -I option for usr headers in include/
include_directories("include")
# include SDL
include_directories("libs/SDL2/include")
# where to find SDL2 libraries 
# I know this is bad, but sometimes doing things right is too hard
link_directories("libs/SDL2/lib")

if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
	link_directories("libs/SDL2/lib/x64")
else ()
	link_directories("libs/SDL2/lib/x86")
endif ()

add_executable(${PROJECT_NAME} ${SOURCE})
target_link_libraries(${PROJECT_NAME} SDL2main SDL2)