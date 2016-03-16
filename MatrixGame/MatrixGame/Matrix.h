#pragma once
#include "Number.h"
#include <vector>

class Matrix
{
public:
    Matrix();
    Matrix(int x, int y);
    int rows;
    int columns;
    std:: vector<std::vector<Number>> numbers;
    int score;
    int sumScore;
    //static void FindVariants(int x, int y);
};

