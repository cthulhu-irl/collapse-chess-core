#ifndef COLLAPSE_CORE_BASE_H_
#define COLLAPSE_CORE_BASE_H_

#include <array>

#define BOARD_MAX_X 8
#define BOARD_MAX_Y 8

namespace collapse {
namespace core {

enum class Status {
    TURN,       /// player's turn
    RANK,       /// player's pawn upgrade role choice
    FOLD,       /// player discarded the game
    CHECK,      /// player's king is threatened
    CHECKMATE,  /// player's king is threatened and is out of move
    STALEMATE   /// player is out of move and player's king is safe
};

/// player and piece type, aka color type
enum class Type {
    WHITE,
    BLACK
};

/// each role of pieces in chess and a relative value for them
enum class PieceRole {
    KING = 10000,  /// NOTE: This might change to 127
    QUEEN = 9,
    BISHOP = 7,
    ROOK = 5,
    KNIGHT = 3,
    PAWN = 1
};

/// a tile/block's coordinates in (x, y) form
class IPoint {
 public:
    virtual bool operator==(const IPoint &other) const;
    virtual bool operator!=(const IPoint &other) const;
    virtual char getX() const = 0;
    virtual char getY() const = 0;
};

class IPlayer {
 public:
    virtual Type getType() const = 0;
    virtual PieceRole getRole() const = 0;
};

template<typename T>
class IMap {
 public:
    virtual T *get(std::size_t x, std::size_t y) const = 0;
    virtual T *set(std::size_t x, std::size_t y, T *ptr) = 0;
    virtual T *delete_at(std::size_t x, std::size_t y) = 0;
    virtual T *move_from_to(std::size_t x1, std::size_t y1,
                            std::size_t x2, std::size_t y2,
                            bool swap=false) = 0;
    virtual T *operator()(std::size_t x, std::size_t y) const = 0;
};

/// a chess piece responsible for satisfying if a move
/// is valid or not, also its color type
class IPiece {
 public:
    virtual bool isValidMove(const IMap<IPiece> &map,
                             const IPoint &src,
                             const IPoint &dst) const = 0;
    virtual Type getType() const = 0;
    virtual PieceRole getRole() const = 0;
    virtual IPiece *clone() const = 0;
};

class IBoard {
 public:
    virtual bool move(const IPoint &src, const IPoint &dst);
    virtual bool upgradeRankPawn(PieceRole role);
    virtual bool redo();
    virtual bool undo();

    virtual bool isValidMove(const IPoint &src, const IPoint &dst) const;
    virtual const IPoint *getLastRankPawn() const;
    virtual Status getStatus() const;
};

class IState {
};

class IChess {
 public:
    virtual const IState &move(const IPlayer &player,
                               const IPoint &src,
                               const IPoint &dst);
    virtual const IState &rank(const IPlayer &player, PieceRole role);
    virtual const IState &fold(const IPlayer &player);
    virtual const IState &reset();
    virtual const IState &redo();
    virtual const IState &undo();

    virtual bool isValidMove(const IPlayer &player,
                             const IPoint &src,
                             const IPoint &dst) const;
    virtual const IState &getState();
};

}  // namespace core
}  // namespace collapse

#endif  // COLLAPSE_CORE_BASE_H_
