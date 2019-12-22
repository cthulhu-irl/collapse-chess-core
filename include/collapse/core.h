#ifndef COLLAPSE_CORE_H_
#define COLLAPSE_CORE_H_

#include <array>

#include "collapse/core/base.h"

namespace collapse {
namespace core {

class Point : public IPoint {
    unsigned char x;
    unsigned char y;

 public:
    Point(unsigned char x, unsigned char y);
    unsigned char getX() override;
    unsigned char getY() override;
};

class Piece : public IPiece {
    const Type type;
    const PieceRole role;

 public:
    Type getType() { return type; }
    PieceRole getRole() { return role; }
};

class Player : public IPlayer {
    Type type;

 public:
    explicit Player(Type type) : type(type) {};
    Type getType() { return type; };
};

class Map : public IMap {
    std::array<std::array<IPiece, 8>, 8> *table;

 public:
    Map();
    explicit Map(std::array<std::array<IPiece, 8>, 8> &&init_table);
    Map(std::initializer_list<std::array<PieceRole, 8>> init_table);
    std::array<IPiece, 8> &operator[](std::size_t index) override;
};

class Board : public IBoard {
    Map map;
    Status status;
    Point last_rank_pawn;

 public:
    explicit Board(Map &map);
    ~Board() override;
    bool move(const IPoint &src, const IPoint &dst) override;
    bool upgradeRankPawn(PieceRole role) override;
    bool isValidMove(const IPoint &src, const IPoint &dst) override;
};

class State : public IState {
 public:
    IPlayer &player;
    Status status;

    State(IPlayer &player, Status status)
        : player(player)
        , status(status)
    {};
    ~State() override {}; // nothing to take care of...
};

class Chess : public IChess {
    Board board;
    State state;

 public:
    IPlayer &player_black;
    IPlayer &player_white;
    IMap &map_init;

    Chess(const IPlayer &white,
          const IPlayer &black,
          const IMap &map);

    const IState &move(const IPlayer &player,
                       const IPoint &src,
                       const IPoint &dst);
    const IState &rank(const IPlayer &player, PieceRole role);
    const IState &fold(const IPlayer &player);
    const IState &reset();

    const IState &getState();
};

}  // namespace core
}  // namespace collapse

#endif  // COLLAPSE_CORE_H_
