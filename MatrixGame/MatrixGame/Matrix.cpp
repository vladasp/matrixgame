#include "stdafx.h"
#include "Matrix.h"
using namespace std;

Matrix::Matrix()
{
    rows = 1;
    columns = 1;
    score = 0;
    sumScore = 0;

    numbers = vector<vector<Number>>(rows);
    for (size_t i = 0; i < rows; i++)
    {
        numbers[i].resize(columns);
        for (size_t j = 0; j < columns; j++)
        {
            numbers[i][j] = Number();
        }
    }
}

Matrix::Matrix(int x, int y)
{
    rows = x;
    columns = y;
    score = 0;
    sumScore = 0;

    numbers = vector<vector<Number>>(columns);
    for (size_t i = 0; i < columns; i++)
    {
        numbers[i].resize(rows);
        for (size_t j = 0; j < rows; j++)
        {
            numbers[i][j] = Number();
        }
    }
}


