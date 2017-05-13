#include <iostream>
#include <stdlib.h> //<-- Using this for exit.
#include <SDL.h> //<-- Using this for graphics.

/* Global Constants */
unsigned int width = 640; //Defining the window height.
unsigned int height = 480; //Defining the window width.

// initSDL ... initalize SDL and all of it components.
void initSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Unable to initialize SDL. :(" << std::endl;
        //If it doesn't work display error and quit.
        exit(EXIT_FAILURE);
    }
}

// setRenderProperties ... Set the draw properties of the renderer and clear the screen.
void setRenderProperties(SDL_Renderer* &renderer) {
    //Set to black and clear the screen.
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    //Set the color to white.
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
}

// main ... Main function, inits everything and then enters a for loop acting as rotation.
int main(int argc, char *argv[]) {
    //Initialize SDL with everything it needs.
    initSDL();

    /* Context Variables */
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    //Assign their values.
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);

    //Set the properties of a renderer.
    setRenderProperties(renderer);

    return 0;
}
