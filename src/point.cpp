#include "collapse/core.h"

using namespace collapse;
using namespace core;

/// Take `x` and `y` as coordinates, and save them as 0..7 numbers
/// `x` can be 1..8 or a..h as in chess board
/// `y` can only be 1..8
Point::Point(char x, char y)
{
    // 1..8 range
    if (1 <= x && x <= 8)
        this->x = x-1;

    // a..h range
    else if ('a' <= x && x <= 'h')
        this->x = x-'a';

    // otherwise throw an exception
    else
        throw "PointException should be replaced in here";

    // check if 1 <= y <= 8, then assign
    if (1 <= y && y <= 8)
        this->y = y-1;

    // otherwise throw an exception
    else
        throw "PointException should be replaced in here";
}

inline bool
Point::operator==(const IPoint &other) const
{
    return ((this->getX() == other.getX())
            && this->getY() == other.getY());
}

inline bool
Point::operator!=(const IPoint &other) const
{
    return !(*this == other);
}

char
Point::getX() const
{
    return this->x;
}

char
Point::getY() const
{
    return this->y;
}
