# Collapse Chess Core

libcollapse-core is a chess logic library, with the goal of simplicity, modularity and flexibility.

Currently the targeted platform is just GNU/Linux, and there are no ports for other programming languages (or platform).

it's about to be written in C++. (not any particular reason)

## Entities

The type of each entity is written right next to its name.  

**NOTE**: TBD stands for "To Be Decided", meaning it's not specified yet.  
**NOTE**: Each entity will be linked to its own document for details when document is created.  

*   [Chess](./entities/chess.md) : Class
*   [Player](./entities/player.md) : Class
*   [Map](./entities/map.md) : Class
*   [Board](./entities/board.md) : Class
*   [State](./entities/state.md) : Class
*   [Point](./entities/point.md) : Class
*   [Status](./entities/status.md) : Enum
*   [Type](./entities/type.md) : Enum
*   [Piece](./entities/piece.md) : Abstract Class
    *   [King](./entities/king.md) : Class
    *   Queen : Class
    *   Bishop : Class
    *   Knight : Class
    *   Rook : Class
    *   Pawn : Class
*   [PieceRole](./entities/piece_role.md) : Enum

