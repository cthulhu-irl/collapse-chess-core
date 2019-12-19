# Rook Class : Piece

Rook class implements [Piece](./piece.md) interface, along with role and type properties and their getters.

Rook, as in regular chess rules, can move both vertically and horizontally.

The isValidMove method **only** checks for **piece specific rules**, but nothing else like destination be opposite type.

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
        > is valid for a Rook in chess or not.
        > 
        > The checks are as follow:
        > *   check if `dst` and `src` have either vertical or 
        >     or horizontal linear relation.
        > *   check if there aren't any other pieces in middle 
        >     of a line between `src` and `dst`.

    *   Type getType()
        > returns `type` of this piece.

    *   Role getRole()
        > returns `role` of this piece. (ROOK)
