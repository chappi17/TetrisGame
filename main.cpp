#include <iostream>
#include <raylib.h>
#include "grid.h"
#include "blocks.cpp"
using namespace std;

Color darkGreen = Color{20,160,133,255};


int main () {

    const int screenWidth = 300;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Tetris Game");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.Print();

    LBlock lblock = LBlock();
    TBlock tblock = TBlock();
    tblock.Move(4,3);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(DARKBLUE);
        grid.Draw();
        tblock.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}