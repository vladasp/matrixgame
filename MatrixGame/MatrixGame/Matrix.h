#pragma once
#include "Number.h"
#include <iostream>
#include <vector>
#include <string>


class Matrix
{
public:
    Matrix();
    Matrix(int x, int y);
    int rows;
    int columns;
    std:: vector<std::vector<Number>> numbers;
    int score;
    std:: string scoreStr;
    int sumScore;
    bool canMoove;

    void FindVariants(std::vector<Matrix>& variants, Matrix& bestVariant, int x, int y);
};

