#include <iostream>
#include <raylib.h>
#include "game.h"
using namespace std;

double lastUpdatedTime= 0;

bool EventTriggred(double interval)
{
    double currentTime = GetTime();
    if(currentTime - lastUpdatedTime >= interval)
    {
        lastUpdatedTime = currentTime;
        return true;
    }
    return false;
}

int main () {

    const int screenWidth = 300;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Tetris Game");
    SetTargetFPS(60);

    Game game = Game();

    while (WindowShouldClose() == false)
    {
        game.HandleInput();
        if(EventTriggred(0.2))
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(DARKBLUE);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}