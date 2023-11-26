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
    int id;

    map<int,vector<Position>> cells;    

~Block();

    private:
    int cellSize;
    int roattionState;
    std::vector<Color> colors;

};