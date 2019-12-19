# Knight Class : Piece

Knight class implements [Piece](./piece.md) interface, along with role and type properties and their getters.

Knight, as in regular chess rules, can only move L-like. meaning the difference of its source (current position) and its destination should be in the form of (x, y) should be one of the following:
*   (2, 1)
*   (1, 2)
*   (-2, 1)
*   (-1, 2)
*   (-2, -1)
*   (-1, -2)

(*it can be checked like this: (abs(delta x) + abs(delta y)) == 3*)

Please refer to [Chess Knight's Wikipedia][wiki-knight] page for further information and visuals.

[wiki-knight]: https://en.wikipedia.org/wiki/Knight_(chess)#Placement_and_movement

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
        > is valid for a Knight in chess or not.
        > 
        > The checks are as follow:
        > *   check if 
        >     `(abs(dst.x - dst.x) + abs(dst.y - src.y)) == 3`.

    *   Type getType()
        > returns `type` of this piece.

    *   Role getRole()
        > returns `role` of this piece. (KNIGHT)

