# Status Enum

Status declares the status of a board and/or game (e.g. check, checkmate, turn, fold, etc.).

## Enumerators

*   `TURN`

    > It's a player's turn to make a move.

*   `RANK`

    > A pawn chess has ranked (reached 8th rank in Y-axis in board) 
    > and thus player is required to upgrade it to another role.

*   `FOLD`

    > A player has folded (discarded the game) 
    > and thus game is finished.  
    > opposite player is **winner**.

*   `CHECK`

    > It's a player's turn to make a move, though also notifying 
    > the player is in a **check** state meaning player's king 
    > is threatened.

*   `CHECKMATE`

    > It means a player's king is threatened and also the player 
    > is out of move to rescue the king.  
    > opposite player is **winner**.

*   `STALEMATE`

    > It means a player has no move that doesn't end up 
    > in checkmate.  
    > this is called draw, no one is winner.

