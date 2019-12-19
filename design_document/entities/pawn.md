# Pawn Class : Piece

Pawn class implements [Piece](./piece.md) interface, along with role and type properties and their getters.

Pawn, as in regular chess rules, can move in 3 forms:
1.  The first move can be 2 blocks forward only if there aren't anything in those blocks.
2.  Pawn can move 1 block forward if there's nothing towards it.
3.  Pawn can move one block diagonally only if attacking.

**NOTE**: Pawn doesn't attack on forward, so this class is also responsible to check for this case as well. means checking if a forward move doesn't end up in any other piece's face!

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
        > is valid for a Pawn in chess or not.
        > 
        > The checks are as follow:
        > *   check if `dst.y - src.y` equals one and 
        >     `abs(dst.x - src.x) == 1` and the pice at `dst`
        >     is opposite type.
        >
        > *   otherwise check if `dst.x - dst.x` equals to 0 
        >     and `dst.y - src.y` equal to 1 or 2.
        >
        > *   then checks if there aren't any other pieces 
        >     in between `src` and `dst` including `dst` too.
        >     (there shouldn't be any piece at `dst` too).

    *   Type getType()
        > returns `type` of this piece.

    *   Role getRole()
        > returns `role` of this piece. (PAWN)
