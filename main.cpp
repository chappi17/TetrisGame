#include <iostream>
#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>
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

    const int screenWidth = 500;
    const int screenHeight = 620;


    InitWindow(screenWidth, screenHeight, "Tetris Game");
    SetTargetFPS(60);
    // Must under InitWindow
    Font font = LoadFontEx("Font/monogram.ttf",64,0,0);
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
        DrawTextEx(font,"Score",{350,15},38,2,WHITE);
        DrawTextEx(font,"Next",{360,175},38,2,WHITE);
        if(game.GameOver)
        {
            DrawTextEx(font,"Game Over",{320,450},38,2,WHITE);
        }
        DrawRectangleRounded({320,55,170,60},0.3,6,lightBlue);
        
        char scoreText[10];
        sprintf(scoreText,"%d",game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText,38,2);

        DrawTextEx(font,scoreText,{320+(170-textSize.x)/2,65},38,2,WHITE);
        DrawRectangleRounded({320,215,170,180},0.3,6,lightBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}