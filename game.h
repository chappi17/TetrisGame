#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
public:
    Game();
    ~Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    void SpaceBar();
    Grid grid;
    bool GameOver;
    Music music;
    int score;
    
private:
    void MoveBlockLeft();
    void MoveBlockRight();
    Block GetRandomBlock();
    vector<Block>GetAllBlocks();
    bool IsBlockOutSide();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int lineCleared, int moveDownPoints);
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
    Sound rotateSound;
    Sound clearSound;
};