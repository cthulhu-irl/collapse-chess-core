# Queen Class : Piece

Queen class implements [Piece](./piece.md) interface, along with role and type properties and their getters.

Queen, as in regular chess rules, can move horizontally, vertically and diagonally.

The isValidMove method **only** checks for **piece specific rules**, but nothing else like destinition be opposite type.

## Properties

Each property is described in format "\<name\> : \<type\>" under its access attribute.

*   private:
    *   type : Type
    *   role : Role

## Methods

Each method is declared in **simple** C++ method prototype form.

**NOTE**: it's **simplified**! meaning type notations are not **exact** but from same class. being *const* or *pointer* or etc.. will be decided later.

*   constructor(s):  
    *   Piece(Type type)

*   public:
    *   bool isValidMove(Map map, Point src, Point dst)
        > checks if a move from `src` to `dst` in this map, 
        > is valid for a King in chess or not.
        > 
        > The checks are as follow:
        > *   if it's a valid castling move
        > *   if `dst` and `src` have horizontal, vertical 
        >     or diagonal linear relation.
        > *   check if there aren't any other pieces in middle of 
        >     a line between `dst` and `src`.

    *   Type getType()
        > returns `type` of this piece.

    *   Role getRole()
        > returns `role` of this piece. (QUEEN)

