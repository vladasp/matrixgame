#include "stdafx.h"
#include "Number.h"
#include <stdlib.h>
using namespace std;

Number::Number()
{
    int min = 0;
    int max = 5;
    isSelected = false;
    value = min + rand() % (max - min);
}

Number& Number::operator=(Number & number)
{
    isSelected = number.isSelected;
    value = number.value;
    x = number.x;
    y = number.y;
    return *this;
}


