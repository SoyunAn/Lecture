#ifndef _RECTANGLE_H__
#define _RECTANGLE_H__

#include "point.h"

class Rectangle
{
    Point upleft;
    Point lowRight;

public:
    Rectangle(const int& x1, const int& y1, const int& x2, const int& y2);
    void ShowRexInfo() const;
};

#endif