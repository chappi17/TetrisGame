#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

using namespace std;

class Block
{
    public:
    Block();
    void Draw();
    int id;

    map<int,vector<Position>> cells;    

    private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;

};