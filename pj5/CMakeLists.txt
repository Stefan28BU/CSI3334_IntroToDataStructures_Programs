cmake_minimum_required(VERSION 3.8)
project(pj5)

set(CMAKE_CXX_STANDARD 11)

include_directories(/Library/Frameworks/SDL2_mixer.framework)
include_directories(/Library/Frameworks/SDL2.framework)
link_directories(/Library/Frameworks/SDL2_mixer.framework)
link_directories(/Library/Frameworks/SDL2.framework)

add_executable(pj5 main.cpp SDL_Plotter.h)
target_link_libraries(pj5 /Library/Frameworks/SDL2_mixer.framework)
target_link_libraries(pj5 /Library/Frameworks/SDL2.framework)