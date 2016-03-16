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
    canMoove = true;
    scoreStr = "";

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

void Matrix::FindVariants(vector<Matrix>& variants, Matrix& bestVariant, int x, int y)
{
    if (canMoove)
    {
        numbers[x][y].isSelected = true;
        sumScore = sumScore + numbers[x][y].value;
        scoreStr = scoreStr + to_string(numbers[x][y].value);
        score = atoi(scoreStr.c_str());

        if (sumScore == 10)
        {
            variants.insert(variants.end(), *this);
            if (bestVariant.score < score) bestVariant = *this;
            canMoove = false;
        }
        else if (sumScore < 10)
        {
            if (x != 0 && x != rows - 1 && y != 0 && y != columns - 1)
            {
                if (!numbers[x + 1][y].isSelected || !numbers[x - 1][y].isSelected || !numbers[x][y + 1].isSelected || !numbers[x][y - 1].isSelected)
                {
                    if (!numbers[x + 1][y].isSelected)
                    {
                        FindVariants(variants, bestVariant, x + 1, y);
                    }
                    if (!numbers[x - 1][y].isSelected)
                    {
                        FindVariants(variants, bestVariant, x - 1, y);
                    }
                    if (!numbers[x][y + 1].isSelected)
                    {
                        FindVariants(variants, bestVariant, x, y + 1);
                    }
                    if (!numbers[x][y - 1].isSelected)
                    {
                        FindVariants(variants, bestVariant, x, y - 1);
                    }
                }
                else
                {
                    canMoove = false;
                }
            }
            //Upper wall
            else if (x == 0)
            {
                if (y == 0)
                {
                    if (!numbers[x + 1][y].isSelected || !numbers[x][y + 1].isSelected)
                    {
                        if (!numbers[x + 1][y].isSelected)
                        {
                            FindVariants(variants, bestVariant, x + 1, y);
                        }
                        if (!numbers[x][y + 1].isSelected)
                        {
                            FindVariants(variants, bestVariant, x, y + 1);
                        }
                    }
                    else
                    {
                        canMoove = false;
                    }
                }
                else if (y == columns - 1)
                {
                    if (!numbers[x + 1][y].isSelected || !numbers[x][y - 1].isSelected)
                    {
                        if (!numbers[x + 1][y].isSelected)
                        {
                            FindVariants(variants, bestVariant, x + 1, y);
                        }
                        if (!numbers[x][y - 1].isSelected)
                        {
                            FindVariants(variants, bestVariant, x, y - 1);
                        }
                    }
                    else
                    {
                        canMoove = false;
                    }
                }
                else
                {
                    if (!numbers[x + 1][y].isSelected || !numbers[x][y + 1].isSelected || !numbers[x][y - 1].isSelected)
                    {
                        if (!numbers[x + 1][y].isSelected)
                        {
                            FindVariants(variants, bestVariant, x + 1, y);
                        }
                        if (!numbers[x][y + 1].isSelected)
                        {
                            FindVariants(variants, bestVariant, x, y + 1);
                        }
                        if (!numbers[x][y - 1].isSelected)
                        {
                            FindVariants(variants, bestVariant, x, y - 1);
                        }
                    }
                    else
                    {
                        canMoove = false;
                    }
                }
            }
            //Down wall
            else if (x == rows - 1)
            {
                if (y == 0)
                {
                    if (!numbers[x - 1][y].isSelected || !numbers[x][y + 1].isSelected)
                    {
                        if (!numbers[x - 1][y].isSelected)
                        {
                            FindVariants(variants, bestVariant, x - 1, y);
                        }
                        if (!numbers[x][y + 1].isSelected)
                        {
                            FindVariants(variants, bestVariant, x, y + 1);
                        }
                    }
                    else
                    {
                        canMoove = false;
                    }
                }
                else if (y == columns - 1)
                {
                    if (!numbers[x - 1][y].isSelected || !numbers[x][y - 1].isSelected)
                    {
                        if (!numbers[x - 1][y].isSelected)
                        {
                            FindVariants(variants, bestVariant, x - 1, y);
                        }
                        if (!numbers[x][y - 1].isSelected)
                        {
                            FindVariants(variants, bestVariant, x, y - 1);
                        }
                    }
                    else
                    {
                        canMoove = false;
                    }
                }
                else
                {
                    if (!numbers[x - 1][y].isSelected || !numbers[x][y + 1].isSelected && !numbers[x][y - 1].isSelected)
                    {
                        if (!numbers[x - 1][y].isSelected)
                        {
                            FindVariants(variants, bestVariant, x - 1, y);
                        }
                        if (!numbers[x][y + 1].isSelected)
                        {
                            FindVariants(variants, bestVariant, x, y + 1);
                        }
                        if (!numbers[x][y - 1].isSelected)
                        {
                            FindVariants(variants, bestVariant, x, y - 1);
                        }
                    }
                    else
                    {
                        canMoove = false;
                    }
                }
            }
            //Left wall 
            else if (y == 0)
            {
                if (!numbers[x + 1][y].isSelected || !numbers[x - 1][y].isSelected || !numbers[x][y + 1].isSelected)
                {
                    if (!numbers[x + 1][y].isSelected)
                    {
                        FindVariants(variants, bestVariant, x + 1, y);
                    }
                    if (!numbers[x - 1][y].isSelected)
                    {
                        FindVariants(variants, bestVariant, x - 1, y);
                    }
                    if (!numbers[x][y + 1].isSelected)
                    {
                        FindVariants(variants, bestVariant, x, y + 1);
                    }
                }
                else
                {
                    canMoove = false;
                }
            }
            //Right wall
            else if (y == columns - 1)
            {
                if (!numbers[x + 1][y].isSelected || !numbers[x - 1][y].isSelected || !numbers[x][y - 1].isSelected)
                {
                    if (!numbers[x + 1][y].isSelected)
                    {
                        FindVariants(variants, bestVariant, x + 1, y);
                    }
                    if (!numbers[x - 1][y].isSelected)
                    {
                        FindVariants(variants, bestVariant, x - 1, y);
                    }
                    if (!numbers[x][y - 1].isSelected)
                    {
                        FindVariants(variants, bestVariant, x, y - 1);
                    }
                }
                else
                {
                    canMoove = false;
                }
            }
        }
        else
        {
            canMoove = false;
        }
    }
}


