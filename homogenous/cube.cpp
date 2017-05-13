#include <iostream>
#include <stdlib.h> //<-- Using this for exit.
#include <SDL.h> //<-- Using this for graphics.

// initSDL ... initalize SDL and all of it components.
void initSDL() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Unable to initialize SDL. :(" << std::endl;
        //If it doesn't work display error and quit.
        exit(EXIT_FAILURE);
    }
}

// main ... Main function, inits everything and then enters a for loop acting as rotation.
int main() {
    //Initialize SDL with everything it needs.
    initSDL();

    
}
