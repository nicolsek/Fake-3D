#include <iostream>
#include <SDL.h>

/* Global Constants */
short const rows = 12; //Rows for the draw matrix row size.
short const cols = 4; //Cols for the draw matrix col size.

short const width = 640; //Width for window size.
short const height = 480; //Height for window size.

short const widthCenter = width/2; //Center of width.
short const heightCenter = height/2; //Center of height.

// initSDL ... Initialize SDL!
int initSDL() {
    return SDL_Init(SDL_INIT_VIDEO); //TODO: Possibly add keyboard controls to manipulate the 3D projection, (SDL_INIT_EVENTS)
}

// createContext ... Create the window and render context and pass those to the window and renderer variables.
int createContext(SDL_Window* window, SDL_Renderer* renderer) {
    return SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_OPENGL, &window, &renderer); 
}

// setRenderProperties ... Set the properties of the renderer.
int setRenderProperties(SDL_Renderer* renderer) {
    //Set the color to black and clear the screen.
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    //Set the draw color for the renderer.
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    //Everything is great and we're done!
    return 0;
}

// zeroArr ... Zero all the values of the array!
void zeroArr(int** arr) {
    //Please for the sake of god don't segfault.
    for (int row = 0; row < rows; row++) {
        //Set the size of the arr.
        arr[row] =  new int [cols];
        for (int col = 0; col < cols; col++) {
            arr[row][col] = 0;
        }
    }
}

// createDrawMatrix ... Create the draw matrix, holds information about the lines we're going to draw. More specifically the line number and the x0, y0, x1, y1 values.
int** createDrawMatrix() {
    //Creating a reference to the matrix.
    int** drawMatrix;

    //Initialize it with it's starting size.
    drawMatrix = new int [cols];

    //Zero the arr.
    zeroArr(drawMatrix);

    //Manually set ALL of the values ;-;.
    drawMatrix[0][0] = widthCenter - 10;
    drawMatrix[0][1] = heightCenter;
    drawMatrix[0][2] = widthCenter;
    drawMatrix[0][3] = heightCenter + 10;

    drawMatrix[1][0] = widthCenter - 10;
    drawMatrix[1][1] = heightCenter;
    drawMatrix[1][2] = widthCenter - 10;
    drawMatrix[1][3] = heightCenter - 15;

    drawMatrix[2][0] = widthCenter + 10;
    drawMatrix[2][1] = heightCenter;
    drawMatrix[2][2] = widthCenter + 20;
    drawMatrix[2][3] = heightCenter + 10;

    drawMatrix[3][0] = widthCenter + 10;
    drawMatrix[3][1] = heightCenter;
    drawMatrix[3][2] = widthCenter + 10;
    drawMatrix[3][3] = heightCenter - 15;

    drawMatrix[4][0] = widthCenter;
    drawMatrix[4][1] = heightCenter + 10;
    drawMatrix[4][2] = widthCenter;
    drawMatrix[4][3] = heightCenter - 10;

    drawMatrix[5][0] = widthCenter + 20;
    drawMatrix[5][1] = heightCenter - 10;
    drawMatrix[5][2] = widthCenter + 20;
    drawMatrix[5][3] = heightCenter + 10;

    drawMatrix[6][0] = widthCenter + 10;
    drawMatrix[6][1] = heightCenter - 15;
    drawMatrix[6][2] = widthCenter + 20;
    drawMatrix[6][3] = heightCenter - 10;

    drawMatrix[7][0] = widthCenter - 10;
    drawMatrix[7][1] = heightCenter - 15;
    drawMatrix[7][2] = widthCenter;
    drawMatrix[7][3] = heightCenter - 10;

    drawMatrix[8][0] = widthCenter;
    drawMatrix[8][1] = heightCenter + 10;
    drawMatrix[8][2] = widthCenter + 20;
    drawMatrix[8][3] = heightCenter + 10;

    drawMatrix[9][0] = widthCenter;
    drawMatrix[9][1] = heightCenter - 10;
    drawMatrix[9][2] = widthCenter + 20;
    drawMatrix[9][3] = heightCenter - 10;

    drawMatrix[10][0] = widthCenter - 10;
    drawMatrix[10][1] = heightCenter - 15;
    drawMatrix[10][2] = widthCenter + 10;
    drawMatrix[10][3] = heightCenter - 15;

    drawMatrix[11][0] = widthCenter - 10;
    drawMatrix[11][1] = heightCenter;
    drawMatrix[11][2] = widthCenter + 10;
    drawMatrix[11][3] = heightCenter;

    //Took like 5 minutes?
}

// update ... Update the matrix with the degrees theta.
void update(int** arr, int theta) {

}

// draw ... Draw the matrix.
void draw(int** arr, SDL_Renderer* renderer) {
    for (row = 0; row < rows; row++) {
        //Draw the line.
        SDL_RenderDrawLine(renderer, arr[row][0], arr[row][1], arr[row][2] arr[row][3];
    }
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

    //Create the draw matrix, a multidimensional array with points setup for the lines.
    int** drawMatrix = createDrawMatrix();

    //The main 'loop'.
    for (int theta = 0; theta < 360 * 4; theta++) {
        update(drawMatrix, theta);
        draw(drawMatrix);
    }

    return 0;
}
