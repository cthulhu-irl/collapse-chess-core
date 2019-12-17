# Map Class

**NOTE**: this is a class only to be extensible.

## Properties

Each property is described in format "\<name\> : \<type\>" under its access attribute.

**NOTE**: this class requires std::array from standard c++ library.

*   public:
    *   table : std::array\<std::array\<Piece, 8\>, 8\>

## Methods

Each method is described in simple C++ method prototype form.

**NOTE**: it's **simplified**! meaning type notations are not _exact_ but from same class. being *const* or *pointer* or etc. will be decided later.

*   constructor(s):
    *   Map()

        > creates an empty `table` of 8x8.

    *   Map(std::array\<std::array\<PieceRole, 8\>, 8\> table)

        > initializes the table with instances of |Piece| in 
        > each cell corresponding to specified PieceRole in `table`.

