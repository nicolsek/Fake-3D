#include <iostream>
#include <SDL.h>

/* Global Constants */

// initSDL ... Initialize SDL!
int initSDL() {
    return SDL_Init(SDL_INIT_VIDEO); //TODO: Possibly add keyboard controls to manipulate the 3D projection, (SDL_INIT_EVENTS)
}

// createContext ... Create the window and render context and pass those to the window and renderer variables.
int createContext(SDL_Window* window, SDL_Renderer* renderer) {
    return SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_OPENGL, &window, &renderer); 
}

// main ... Does initialization before going into the main loop.
int main(int argc, char* argv[]) {
    if (initSDL() != 0) {
        std::cout << "Unable to initialzie SDL! :(" << std::endl;
        return -1; 
    }

    /* Window and Renderer we'll be using. */
    SDL_Window *window;
    SDL_Renderer *renderer;

    //Create the window and renderer and pass those to our previously created window and renderer.
    if (createContext(window, renderer) != 0) {
        std::cout << "Unable to create viewing context! :(" << std::endl;
    }

    return 0;
}
