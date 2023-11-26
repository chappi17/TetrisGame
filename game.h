#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game
{
public:
    Game();
    Block GetRandomBlock();
    vector<Block>GetAllBlocks();
    void Draw();
    void HandleInput();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    Grid grid;
    
private:
    bool IsBlockOutSide();
    std::vector<Block> blocks;
    Block currentBlock;
    Block nextBlock;
};