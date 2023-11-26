#include <iostream>
#include <raylib.h>
#include "grid.h"
using namespace std;

Color darkGreen = Color{20,160,133,255};


int main () {

    const int screenWidth = 300;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Tetris Game");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.grid[0][0] = 1;
    grid.grid[3][5] = 4;
    grid.grid[17][8] = 7;
    grid.Print();
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(DARKBLUE);
        grid.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}