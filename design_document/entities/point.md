# Point Class

Point class defines a point in table.

This class is also responsible for converting different form of representaions to numeric values 1 to 8 for X and Y axis.

## Properties

Each property is described in format "\<name\> : \<type\>" under its access attribute.

*   private:
    *   x : unsigned char

        > X axis, a number from 1 to 8

    *   y : unsigned char

        > Y axis, a number from 1 to 8

## Methods

Each method is described in simple C++ method prototype form.

**NOTE**: it's **simplified**! meaning type notations are not _exact_ but from same class. being *const* or *pointer* or etc.. will be decided later.

*   constructor(s):
    *   Point(unsigned char x, unsigned char y)

        > `x` must be either 'A' to 'H', or 'a' to 'h',  
        > and `y` must be numeric 1 to 8, or character '1' to '8'

*   public:
    *   unsigned char x()

        > returns property `x`

    *   unsigned char y()

        > returns property `y`

