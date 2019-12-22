#include "collapse/core.h"

using namespace collapse;
using namespace core;

Point::Point(unsigned char x, unsigned char y)
{
    // check if 1 <= x <= 8, then assign
    // otherwise if 'a' <= x <= 'h', then convert and assign
    // otherwise throw an exception

    // check if 1 <= y <= 8, then assign
    // otherwise throw an exception
}

unsigned char
Point::getX() override
{
    return x;
}

unsigned char
Point::getY() override
{
    return y;
}
