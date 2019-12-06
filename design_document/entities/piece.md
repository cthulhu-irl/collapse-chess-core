# Piece Interface

Piece describes what necessary functionality each chess piece implementation (King, Queen, Pawn, etc.) must implement.

Each piece must expose a method that checks if a move from a point coordinates to another is valid or not.

Also each Piece must has a type, exposing if it's black or white.

## Interface/Abstract Methods

Each method is described in **simple** C++ method prototype form.

**NOTE**: it's **simplified**! meaning type notations are not **exact** but from same class. being *const* or *pointer* or etc.. will be decided later.

**NOTE**: no description is available since it's an interface. the purpose of each method is described above.

*   constructor(s):  
    *   Piece(Type type)

*   public:
    *   bool isValidMove(Map map, Point src, Point dst)
    *   Type getType()

