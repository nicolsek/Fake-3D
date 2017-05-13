#include <iostream>
#include <math.h>
#include <SDL.h>

/* Global Constants */
short const rows = 12; //Rows for the draw matrix row size.
short const cols = 4; //Cols for the draw matrix col size.

short const width = 640; //Width for window size.
short const height = 480; //Height for window size.

short const widthCenter = width/2; //Center of width.
short const heightCenter = height/2; //Center of height.

short const scale = 2; //Scale for drawing.

// initSDL ... Initialize SDL!
int initSDL() {
    return SDL_Init(SDL_INIT_EVERYTHING); //TODO: Possibly add keyboard controls to manipulate the 3D projection, (SDL_INIT_EVENTS)
}

// createWindow ... Creates a window and returns it.
SDL_Window* createWindow(const char* title) {
    //Reference to window.
    SDL_Window* window;
    
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    return window;
}

// createRenderer ... Create a renderer and return it.
SDL_Renderer* createRenderer(SDL_Window* window) {
    //Init variable.
    SDL_Renderer* renderer;

    //Create the renderer.
    renderer = SDL_CreateRenderer(window, -1, 0);

    return renderer;
}


// printMatrix ... Prints the matrix to standard output.
void printMatrix(int **arr) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols;  col++) {
            std::cout << arr[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

// zeroArr ... Zero all the values of the array!
void zeroArr(int **arr) {
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
    int **drawMatrix;

    //Initialize it with it's starting size.
    drawMatrix = new int *[rows];

    //Zero the arr.
    zeroArr(drawMatrix);

    //Manually set ALL of the values ;-;.
    drawMatrix[0][0] = widthCenter - 10 * scale;
    drawMatrix[0][1] = heightCenter;
    drawMatrix[0][2] = widthCenter;
    drawMatrix[0][3] = heightCenter + 10 * scale;

    drawMatrix[1][0] = widthCenter - 10 * scale;
    drawMatrix[1][1] = heightCenter;
    drawMatrix[1][2] = widthCenter - 10 * scale;
    drawMatrix[1][3] = heightCenter - 15 * scale;

    drawMatrix[2][0] = widthCenter + 10 * scale;
    drawMatrix[2][1] = heightCenter;
    drawMatrix[2][2] = widthCenter + 20 * scale;
    drawMatrix[2][3] = heightCenter + 10 * scale;

    drawMatrix[3][0] = widthCenter + 10 * scale;
    drawMatrix[3][1] = heightCenter;
    drawMatrix[3][2] = widthCenter + 10 * scale;
    drawMatrix[3][3] = heightCenter - 15 * scale;

    drawMatrix[4][0] = widthCenter;
    drawMatrix[4][1] = heightCenter + 10 * scale;
    drawMatrix[4][2] = widthCenter;
    drawMatrix[4][3] = heightCenter - 10 * scale;

    drawMatrix[5][0] = widthCenter + 20 * scale;
    drawMatrix[5][1] = heightCenter - 10 * scale;
    drawMatrix[5][2] = widthCenter + 20 * scale;
    drawMatrix[5][3] = heightCenter + 10 * scale;

    drawMatrix[6][0] = widthCenter + 10 * scale;
    drawMatrix[6][1] = heightCenter - 15 * scale;
    drawMatrix[6][2] = widthCenter + 20 * scale;
    drawMatrix[6][3] = heightCenter - 10 * scale;

    drawMatrix[7][0] = widthCenter - 10 * scale;
    drawMatrix[7][1] = heightCenter - 15 * scale;
    drawMatrix[7][2] = widthCenter;
    drawMatrix[7][3] = heightCenter - 10 * scale;

    drawMatrix[8][0] = widthCenter;
    drawMatrix[8][1] = heightCenter + 10 * scale;
    drawMatrix[8][2] = widthCenter + 20 * scale;
    drawMatrix[8][3] = heightCenter + 10 * scale;

    drawMatrix[9][0] = widthCenter;
    drawMatrix[9][1] = heightCenter - 10 * scale;
    drawMatrix[9][2] = widthCenter + 20 * scale;
    drawMatrix[9][3] = heightCenter - 10 * scale;

    drawMatrix[10][0] = widthCenter - 10 * scale;
    drawMatrix[10][1] = heightCenter - 15 * scale;
    drawMatrix[10][2] = widthCenter + 10 * scale;
    drawMatrix[10][3] = heightCenter - 15 * scale;

    drawMatrix[11][0] = widthCenter - 10 * scale;
    drawMatrix[11][1] = heightCenter;
    drawMatrix[11][2] = widthCenter + 10 * scale;
    drawMatrix[11][3] = heightCenter;

    //Took like 5 minutes?

    return drawMatrix;
}

// update ... Update the matrix with the degrees theta.
void update(int **arr, int theta) {
    
    for (int row = 0; row < rows; row++){
        int x0 = arr[row][0];
        int y0 = arr[row][1];
        int x1 = arr[row][2];
        int y1 = arr[row][3];

        arr[row][0] = round(x0*cos(theta) - y0*sin(theta));
        arr[row][1] = round(x0*sin(theta) + y0*cos(theta));
        arr[row][2] = round(x1*cos(theta) - y1*sin(theta));
        arr[row][3] = round(x1*sin(theta) + y1*cos(theta));
    }
}

// draw ... Draw the matrix.
void draw(int **arr, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    
    for (int row = 0; row < rows; row++) {

        //Set color to white.
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);


        SDL_RenderDrawLine(renderer, arr[row][0], arr[row][1], arr[row][2], arr[row][3]);

        SDL_RenderPresent(renderer);

    }
}

// main ... Does initialization before going into the main loop.
int main(int argc, char* argv[]) {
    if (initSDL() != 0) {
        std::cout << "Unable to initialzie SDL! :(" << std::endl;
        return -1; 
    }

    /* Window and Renderer we'll be using. */
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    window = createWindow("Cube");
    renderer = createRenderer(window);

    //Create the draw matrix, a multidimensional array with points setup for the lines.
    int **drawMatrix = createDrawMatrix();

    for (int theta = 0; theta < 360; theta++) {
        update(drawMatrix, theta);
        draw(drawMatrix, renderer);
        SDL_Delay(500);
    }

    return 0;
}
