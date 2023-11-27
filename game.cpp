#include "game.h"
#include <random>

Game::Game()
{
    grid = Grid();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    GameOver = false;
    score = 0;
    InitAudioDevice();
    music = LoadMusicStream("Sound/music.mp3");
    PlayMusicStream(music);
    rotateSound = LoadSound("Sound/rotate.mp3");
    clearSound = LoadSound("Sound/clear.mp3");
}

Game::~Game()
{
    UnloadSound(clearSound);
    UnloadSound(rotateSound);
    UnloadMusicStream(music);
    CloseAudioDevice();
}

Block Game::GetRandomBlock()
{
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    // erase Index atter randomIndex choose.
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw(11,11);
    switch (nextBlock.id)
    {
    case 3:
        nextBlock.Draw(255,290);
        break;
    case 4:
        nextBlock.Draw(255,280);
        break;
    
    default:
        nextBlock.Draw(270,270);
        break;
    };
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    if(GameOver && keyPressed !=0)
    {
        GameOver = false;
        Reset();
    }
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;

    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        break;
    case KEY_UP:
        RotateBlock();
        break;
    case KEY_SPACE:
        SpaceBar();
        break;

    default:
        break;
    }
}

void Game::MoveBlockLeft()
{
    if (!GameOver)
    {
        currentBlock.Move(0, -1);
        if (IsBlockOutSide() || BlockFits() == false)
        {
            currentBlock.Move(0, 1);
        }
    }
}

void Game::MoveBlockRight()
{
    if (!GameOver)
    {
        currentBlock.Move(0, 1);
        if (IsBlockOutSide() || BlockFits() == false)
        {
            currentBlock.Move(0, -1);
        }
    }
}

void Game::MoveBlockDown()
{
    if (!GameOver)
    {
        currentBlock.Move(1, 0);
        if (IsBlockOutSide() || BlockFits() == false)
        {
            currentBlock.Move(-1, 0);
            LockBlock();
        }
    }
}

void Game::SpaceBar()
{
    if(!GameOver)
    {
        while (!IsBlockOutSide() && BlockFits())
        {
            currentBlock.Move(1,0);
        }
        currentBlock.Move(-1,0);
        LockBlock();
    }
}

bool Game::IsBlockOutSide()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.IsCellOutside(item.row, item.column))
        {
            return true;
        }
    }
    return false;
}

void Game::RotateBlock()
{
    if (!GameOver)
    {
        currentBlock.Rotate();
        if (IsBlockOutSide() || BlockFits() == false)
        {
            currentBlock.UndoRatation();
        }
    }
    else
    {
        PlaySound(rotateSound);
    }
}

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles)
    {
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if (BlockFits() == false)
    {
        GameOver = true;
    }
    // Constructor has assign newxBlock = GetRandomBlock() but, after that nextBlock need to reassign GetRandomBlock.
    nextBlock = GetRandomBlock();
    int rowCleared = grid.ClearFullRows();
    if(rowCleared > 0)
    {
        PlaySound(clearSound);
        UpdateScore(rowCleared,0);
    }
}

bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for (Position item : tiles)
    {
        if (grid.IsCellEmpty(item.row, item.column) == false)
        {
            return false;
        }
    }
    return true;
}

void Game::Reset()
{
    grid.Initialize();
    blocks= GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score =0;
}

void Game::UpdateScore(int lineCleared, int moveDownPoints)
{
    switch (lineCleared)
    {
    case 1:
        score += 100;
        break;
    case 2 :
        score += 300;
        break;
    case 3 :
        score += 500;
        break;
    default:
        break;
    }

    score+= moveDownPoints;
}


