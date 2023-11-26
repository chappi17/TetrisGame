#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

using namespace std;

class Block
{public:

    Block();
    void Draw();
    void Move(int rows, int columns);
    int id;
    map<int,vector<Position>> cells;  
    vector<Position> GetCellPositions(); 

private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;
};