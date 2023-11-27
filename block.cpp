#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState =0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset =0;
}

void Block::Draw(int offsetX, int offsetY)
{
    std::vector<Position> tiles = GetCellPositions();
    for(Position item : tiles)
    {
            DrawRectangle(item.column*cellSize +offsetX,item.row*cellSize+offsetY,cellSize-1,cellSize-1,colors[id]);
    }

}

void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

void Block::Rotate()
{
    rotationState++;
    //if numIndex is reachout 0~3 -> Make them back to 0 
    if(rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}

void Block::UndoRatation()
{
    rotationState --;
    if(rotationState== -1)
    {   // return to max rotation index
        rotationState = cells.size()-1;
    }
}

vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState];
    std::vector<Position> movedTiles;

    for(Position item : tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}
