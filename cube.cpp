#include <iostream>
#include <SDL.h>

/* Global Constants */

// initSDL ... Initialize SDL!
int initSDL() {
    return SDL_Init(SDL_INIT_VIDEO); //TODO: Possibly add keyboard controls to manipulate the 3D projection, (SDL_INIT_EVENTS)
}

// main ... Does initialization before going into the main loop.
int main(int argc, char* argv[]) {
    if (initSDL() != 0) {
        std::cout << "Unable to initialzie SDL! :(" << std::endl;
        return -1; 
    }

    return 0;
}
