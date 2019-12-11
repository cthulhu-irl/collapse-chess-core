# King Class : Piece

King class implements Piece interface, along with role and type properties and getters.

King, as in regular chess rules, can move only one block, it can move 2 blocks in [castling](https://en.wikipedia.org/wiki/Castling) move.

The isValidMove method **only** checks for **piece specific rules**, but nothing else like destinition be opposite type.

## Properties

Each property is described in format "\<name\> : \<type\>" under its access attribute.

*   private:
    *   type : Type

*   public:
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
        > *   if `dst` and `src` differ exactly one block.

    *   Type getType()
        > returns `type` of this piece.

    *   Role getRole()
        > returns `role` of this piece. (KING)
