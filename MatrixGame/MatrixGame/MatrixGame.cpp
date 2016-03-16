#include "stdafx.h"
#include <iostream>

#include "Matrix.h"

using namespace std;

int rows, columns;
void PrintMatrix(Matrix& enterDataMatrix);
vector<Matrix> variants;
Matrix bestVariant;
void Initialization();
bool isPrintStartMatrix;
Matrix enterDataMatrix;

int main()
{
    //Initial default matrix 
    Initialization();

    //Print default matrix
    PrintMatrix(enterDataMatrix);

    //Calculation
    bestVariant = enterDataMatrix;
    cout << "Start calculation" << endl;
    for (int x = 0; x < enterDataMatrix.rows; x++)
    {
        for (int y = 0; y < enterDataMatrix.columns; y++)
        {
            //Reset data of variant for next new
            enterDataMatrix.canMoove = true;
            enterDataMatrix.score = 0;
            enterDataMatrix.sumScore = 0;
            enterDataMatrix.scoreStr = "";
            for (size_t i = 0; i < columns; i++)
            {
                enterDataMatrix.numbers[i].resize(enterDataMatrix.rows);
                for (size_t j = 0; j < rows; j++)
                {
                    enterDataMatrix.numbers[i][j].isSelected = false;
                }
            }

            enterDataMatrix.FindVariants(variants, bestVariant, x, y);
        }
    }
    //Calculation(enterDataMatrix);
    cout << "End calculation" << endl;

    //Print all variants
    for each (Matrix matrix in variants)
    {
        PrintMatrix(matrix);
    }

    //Print best score 
    cout << "//////////////////////" << endl;
    cout << "//Best score variant//" << endl;
    cout << "//////////////////////" << endl;

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
    cout << "#############################" << endl;
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
                if (!enterDataMatrix.numbers[i][j].isSelected)
                {
                    cout << "+";
                }
                else
                {
                    cout << enterDataMatrix.numbers[i][j].value;
                }
            }
        }
        cout << endl;
    }
    if (isPrintStartMatrix) cout << "Score: " << enterDataMatrix.score << endl;
    cout << "#############################" << endl;
    cout <<  endl;
    if (!isPrintStartMatrix) isPrintStartMatrix = true;
}

