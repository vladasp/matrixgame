#include "stdafx.h"
#include <iostream>

#include "Matrix.h"

using namespace std;

int rows, columns;
void PrintMatrix(Matrix& enterDataMatrix);
vector<Matrix> variants;
Matrix bestVariant;
void Calculation(Matrix& enterDataMatrix);
void Initialization();
bool isPrintStartMatrix;
Matrix enterDataMatrix;

int main()
{
    //Initial start 
    Initialization();

    //Print default matrix
    PrintMatrix(enterDataMatrix);

    //Calculation
    bestVariant = enterDataMatrix;
    Calculation(enterDataMatrix);

    //Print all variants
    for each (Matrix matrix in variants)
    {
        //PrintMatrix(matrix);
    }

    //Print best score variant
    cout << "Best score variant" << endl;
    PrintMatrix(bestVariant);

    system("pause");
    return 0;
}
void Initialization() 
{
    cout << "Enter a count of rows" << endl;
    cin >> rows;
    cout << "Enter a count of columns" << endl;
    cin >> columns;
    isPrintStartMatrix = false;
    enterDataMatrix = Matrix(rows, columns);
}

void PrintMatrix(Matrix& enterDataMatrix)
{
    cout << "****************************" << endl;
    if (!isPrintStartMatrix)
    {
        cout << "Start matrix" << endl;
    }
    for (int i = 0; i < enterDataMatrix.columns; i++)
    {
        enterDataMatrix.numbers[i].resize(enterDataMatrix.rows);
        for (int j = 0; j < enterDataMatrix.rows; j++)
        {
            if (!isPrintStartMatrix)
            {
                cout << enterDataMatrix.numbers[i][j].value;
            }
            else 
            {
                if (enterDataMatrix.numbers[i][j].isSelected)
                {
                    cout << "+ ";
                }
                else
                {
                    cout << enterDataMatrix.numbers[i][j].value;
                }
            }
        }
        cout << endl;
    }
    if (isPrintStartMatrix) cout << "Score: " + enterDataMatrix.score << endl;
    cout << "****************************" << endl;
    if (!isPrintStartMatrix) isPrintStartMatrix = true;
}

void Calculation(Matrix& enterDataMatrix)
{
    for (int x = 0; x < enterDataMatrix.rows; x++)
    {
        for (int y = 0; y < enterDataMatrix.columns; y++)
        {
            string score;
            bool canMoove = true;
            int currentX = x;
            int currentY = y;
            enterDataMatrix.numbers[x][y].isSelected = true;
            score += enterDataMatrix.numbers[x][y].value;
            enterDataMatrix.sumScore += enterDataMatrix.numbers[x][x].value;

            while (canMoove && enterDataMatrix.sumScore >= 10)
            {
                //Current position in the middle
                if (x != 0 && x != enterDataMatrix.rows - 1 && y != 0 && y != enterDataMatrix.columns - 1)
                {
                    if (enterDataMatrix.numbers[currentX - 1][currentY].value != 0
                        && enterDataMatrix.numbers[currentX + 1][currentY].value != 0
                        && enterDataMatrix.numbers[currentX][currentY - 1].value != 0
                        && enterDataMatrix.numbers[currentX][currentY + 1].value != 0)
                    {
                        if (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX + 1][currentY].value)
                        {
                            //--
                            if (enterDataMatrix.numbers[currentX][currentY - 1].value < enterDataMatrix.numbers[currentX][currentY + 1].value)
                            {
                                currentX = (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX][currentY - 1].value) ? currentX - 1 : currentX;
                                currentY = (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX][currentY - 1].value) ? currentY : currentY - 1;
                            }
                            //-+
                            else
                            {
                                currentX = (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX][currentY - 1].value) ? currentX - 1 : currentX;
                                currentY = (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX][currentY + 1].value) ? currentY : currentY + 1;
                            }
                        }
                        else
                        {
                            //+-
                            if (enterDataMatrix.numbers[currentX][currentY - 1].value < enterDataMatrix.numbers[currentX][currentY + 1].value)
                            {
                                currentX = (enterDataMatrix.numbers[currentX + 1][currentY].value < enterDataMatrix.numbers[currentX][currentY - 1].value) ? currentX + 1 : currentX;
                                currentY = (enterDataMatrix.numbers[currentX + 1][currentY].value < enterDataMatrix.numbers[currentX][currentY - 1].value) ? currentY : currentY - 1;
                            }
                            //++
                            else
                            {
                                currentX = (enterDataMatrix.numbers[currentX + 1][currentY].value < enterDataMatrix.numbers[currentX][currentY - 1].value) ? currentX + 1 : currentX;
                                currentY = (enterDataMatrix.numbers[currentX + 1][currentY].value < enterDataMatrix.numbers[currentX][currentY + 1].value) ? currentY : currentY + 1;
                            }
                        }
                        enterDataMatrix.numbers[currentX][currentY].isSelected = true;
                        score += enterDataMatrix.numbers[currentX][currentY].value;
                        enterDataMatrix.sumScore += enterDataMatrix.numbers[currentX][currentY].value;
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
                        if (enterDataMatrix.numbers[currentX + 1][currentY].value != 0
                            && enterDataMatrix.numbers[currentX][currentY + 1].value != 0)
                        {
                            //++
                            currentX = (enterDataMatrix.numbers[currentX + 1][currentY].value < enterDataMatrix.numbers[currentX][currentY + 1].value) ? currentX + 1 : currentX;
                            currentY = (enterDataMatrix.numbers[currentX + 1][currentY].value < enterDataMatrix.numbers[currentX][currentY + 1].value) ? currentY : currentY + 1;
                            enterDataMatrix.numbers[currentX][currentY].isSelected = true;
                            score += enterDataMatrix.numbers[currentX][currentY].value;
                            enterDataMatrix.sumScore += enterDataMatrix.numbers[currentX][currentY].value;
                        }
                        else
                        {
                            canMoove = false;
                        }
                    }
                    else if (y == enterDataMatrix.columns - 1)
                    {
                        if (enterDataMatrix.numbers[currentX + 1][currentY].value != 0
                            && enterDataMatrix.numbers[currentX][currentY - 1].value != 0)
                        {
                            //+-
                            currentX = (enterDataMatrix.numbers[currentX + 1][currentY].value < enterDataMatrix.numbers[currentX][currentY + 1].value) ? currentX + 1 : currentX;
                            currentY = (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX][currentY + 1].value) ? currentY : currentY - 1;
                            enterDataMatrix.numbers[currentX][currentY].isSelected = true;
                            score += enterDataMatrix.numbers[currentX][currentY].value;
                            enterDataMatrix.sumScore += enterDataMatrix.numbers[currentX][currentY].value;
                        }
                        else
                        {
                            canMoove = false;
                        }
                    }
                    else
                    {
                        if (enterDataMatrix.numbers[currentX + 1][currentY].value != 0
                            && enterDataMatrix.numbers[currentX][currentY - 1].value != 0
                            && enterDataMatrix.numbers[currentX][currentY + 1].value != 0)
                        {
                            //+-
                            if (enterDataMatrix.numbers[currentX][currentY - 1].value < enterDataMatrix.numbers[currentX][currentY + 1].value)
                            {
                                currentX = (enterDataMatrix.numbers[currentX + 1][currentY].value < enterDataMatrix.numbers[currentX][currentY - 1].value) ? currentX + 1 : currentX;
                                currentY = (enterDataMatrix.numbers[currentX + 1][currentY].value < enterDataMatrix.numbers[currentX][currentY - 1].value) ? currentY : currentY - 1;
                            }
                            //++
                            else
                            {
                                currentX = (enterDataMatrix.numbers[currentX + 1][currentY].value < enterDataMatrix.numbers[currentX][currentY + 1].value) ? currentX + 1 : currentX;
                                currentY = (enterDataMatrix.numbers[currentX + 1][currentY].value < enterDataMatrix.numbers[currentX][currentY + 1].value) ? currentY : currentY + 1;
                            }
                            enterDataMatrix.numbers[currentX][currentY].isSelected = true;
                            score += enterDataMatrix.numbers[currentX][currentY].value;
                            enterDataMatrix.sumScore += enterDataMatrix.numbers[currentX][currentY].value;
                        }
                        else
                        {
                            canMoove = false;
                        }
                    }
                }
                //Lower wall
                else if (x == enterDataMatrix.rows - 1)
                {
                    if (y == 0)
                    {
                        if (enterDataMatrix.numbers[currentX - 1][currentY].value != 0
                            && enterDataMatrix.numbers[currentX][currentY + 1].value != 0)
                        {
                            //-+
                            currentX = (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX][currentY + 1].value) ? currentX - 1 : currentX;
                            currentY = (enterDataMatrix.numbers[currentX + 1][currentY].value < enterDataMatrix.numbers[currentX][currentY + 1].value) ? currentY : currentY + 1;
                            enterDataMatrix.numbers[currentX][currentY].isSelected = true;
                            score += enterDataMatrix.numbers[currentX][currentY].value;
                            enterDataMatrix.sumScore += enterDataMatrix.numbers[currentX][currentY].value;
                        }
                        else
                        {
                            canMoove = false;
                        }

                    }
                    else if (y == enterDataMatrix.columns - 1)
                    {
                        if (enterDataMatrix.numbers[currentX - 1][currentY].value != 0
                            && enterDataMatrix.numbers[currentX][currentY - 1].value != 0)
                        {
                            //--
                            currentX = (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX][currentY - 1].value) ? currentX - 1 : currentX;
                            currentY = (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX][currentY - 1].value) ? currentY : currentY - 1;
                            enterDataMatrix.numbers[currentX][currentY].isSelected = true;
                            score += enterDataMatrix.numbers[currentX][currentY].value;
                            enterDataMatrix.sumScore += enterDataMatrix.numbers[currentX][currentY].value;
                        }
                        else
                        {
                            canMoove = false;
                        }

                    }
                    else
                    {
                        if (enterDataMatrix.numbers[currentX - 1][currentY].value != 0
                            && enterDataMatrix.numbers[currentX][currentY - 1].value != 0
                            && enterDataMatrix.numbers[currentX][currentY + 1].value != 0)
                        {
                            //--
                            if (enterDataMatrix.numbers[currentX][currentY - 1].value < enterDataMatrix.numbers[currentX][currentY + 1].value)
                            {
                                currentX = (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX][currentY - 1].value) ? currentX - 1 : currentX;
                                currentY = (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX][currentY - 1].value) ? currentY : currentY - 1;
                            }
                            //-+
                            else
                            {
                                currentX = (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX][currentY + 1].value) ? currentX - 1 : currentX;
                                currentY = (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX][currentY + 1].value) ? currentY : currentY + 1;
                            }
                            enterDataMatrix.numbers[currentX][currentY].isSelected = true;
                            score += enterDataMatrix.numbers[currentX][currentY].value;
                            enterDataMatrix.sumScore += enterDataMatrix.numbers[currentX][currentY].value;
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
                    if (enterDataMatrix.numbers[currentX + 1][currentY].value != 0
                        && enterDataMatrix.numbers[currentX - 1][currentY].value != 0
                        && enterDataMatrix.numbers[currentX][currentY + 1].value != 0)
                    {
                        //-+
                        if (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX + 1][currentY].value)
                        {
                            currentX = (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX][currentY + 1].value) ? currentX - 1 : currentX;
                            currentY = (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX][currentY + 1].value) ? currentY : currentY + 1;
                        }
                        //++
                        else
                        {
                            currentX = (enterDataMatrix.numbers[currentX + 1][currentY].value < enterDataMatrix.numbers[currentX][currentY + 1].value) ? currentX + 1 : currentX;
                            currentY = (enterDataMatrix.numbers[currentX + 1][currentY].value < enterDataMatrix.numbers[currentX][currentY + 1].value) ? currentY : currentY + 1;
                        }
                        enterDataMatrix.numbers[currentX][currentY].isSelected = true;
                        score += enterDataMatrix.numbers[currentX][currentY].value;
                        enterDataMatrix.sumScore += enterDataMatrix.numbers[currentX][currentY].value;
                    }
                    else
                    {
                        canMoove = false;
                    }
                }
                //Right wall
                else if (y == enterDataMatrix.columns - 1)
                {
                    if (enterDataMatrix.numbers[currentX + 1][currentY].value != 0
                        && enterDataMatrix.numbers[currentX - 1][currentY].value != 0
                        && enterDataMatrix.numbers[currentX][currentY - 1].value != 0)
                    {
                        //--
                        if (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX - 1][currentY].value)
                        {
                            currentX = (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX][currentY - 1].value) ? currentX - 1 : currentX;
                            currentY = (enterDataMatrix.numbers[currentX - 1][currentY].value < enterDataMatrix.numbers[currentX][currentY - 1].value) ? currentY : currentY - 1;
                        }
                        //+-
                        else
                        {
                            currentX = (enterDataMatrix.numbers[currentX + 1][currentY].value < enterDataMatrix.numbers[currentX][currentY - 1].value) ? currentX + 1 : currentX;
                            currentY = (enterDataMatrix.numbers[currentX + 1][currentY].value < enterDataMatrix.numbers[currentX][currentY - 1].value) ? currentY : currentY - 1;
                        }
                        enterDataMatrix.numbers[currentX][currentY].isSelected = true;
                        score += enterDataMatrix.numbers[currentX][currentY].value;
                        enterDataMatrix.sumScore += enterDataMatrix.numbers[currentX][currentY].value;
                    }
                    else
                    {
                        canMoove = false;
                    }
                }
                enterDataMatrix.score = atoi(score.c_str());
            }
            if (enterDataMatrix.sumScore == 10) variants.insert(variants.end(), enterDataMatrix);
            if (enterDataMatrix.score > bestVariant.score) bestVariant = enterDataMatrix;
        }
    }
}

