# Board Class

Board class is responsible for keeping the state of pieces (inside a map) and control them (the move action).

this class also exposes a public method for validation of a move.

## Properties

Each property is described in format "\<name\> : \<type\>" under its access attribute.

*   private:
    *   map : Map

        > this property holds the table of pieces.

    *   status : Status

        > this property holds the status of the board.
        > (e.g. turn, fold, checkmate, stalemate, etc..)

## Methods

Each method is described in simple C++ method prototype form.

**NOTE**: it's **simplified**! meaning type notations are not _exact_ but from same class. being *const* or *pointer* or etc.. will be decided later.

*   constructor(s):  
    *   Board(Map map)

*   public:
    *   Status move(Point src, Point dst)

        > makes a move of piece at `src` to `dst` if it's valid.  
        > if there's an opposite piece of `src` is at `dst`,
        > that piece will be removed.

    *   bool isValidMove(Point src, Point dst)

        > checks if a move from piece at `src` to place at 
        > `dst` is valid or not. the validity is checked 
        > first if there is a piece at `src`, then if a 
        > piece at `dst` exists, makes sure that piece at `dst` 
        > isn't the same |Type| as piece at `src`. then checks 
        > if that piece supports such move, then checks if 
        > the current `status` of board and checks the move 
        > against the `status` to be valid.

