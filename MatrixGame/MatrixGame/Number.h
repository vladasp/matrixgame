#pragma once


class Number
{
public:
    Number();
    int x, y;
    bool isSelected;
    int value;
    Number& operator= (Number& number);
};

