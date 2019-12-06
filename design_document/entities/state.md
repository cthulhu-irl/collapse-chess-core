# State Class

State represents the state of a |Chess| game, describing its |Status|, the |Map| of pieces on board, and the opposite |Player| of which one that made the last action.

**NOTE**: this is a class only to be extensible.

## Properties

Each property is described in format "\<name\> : \<type\>" under its access attribute.

*   public:
    *   status : Status

        > status of the board/game.

    *   player : Player

        > oppposite player of the one that made last action.

    *   map : Map

        > map of current board's pieces.

## Methods

Each method is described in simple C++ method prototype form.

**NOTE**: it's **simplified**! meaning type notations are not _exact_ but from same class. being *const* or *pointer* or etc. will be decided later.

*   constructor(s):
    *   State(Status status, Player player, Map map)

        > just sets the right argument to the corresponding property.
