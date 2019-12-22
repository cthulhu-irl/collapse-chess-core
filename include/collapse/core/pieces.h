#ifndef COLLAPSE_CORE_PIECES_H_
#define COLLAPSE_CORE_PIECES_HPP

#include "collapse/core.h"

namespace collapse {
namespace core {

class King : public Piece {
 public:
    King(Type type) : type(type), role(PieceRole.KING) {};
    bool isValidMove(const IPoint &src, const IPoint &dst) override;
};

class Queen : public Piece {
 public:
    Queen(Type type) : type(type), role(PieceRole.QUEEN) {};
    bool isValidMove(const IPoint &src, const IPoint &dst) override;
};

class Bishop : public Piece {
 public:
    Bishop(Type type) : type(type), role(PieceRole.BISHOP) {};
    bool isValidMove(const IPoint &src, const IPoint &dst) override;
};

class Knight : public Piece {
 public:
    Knight(Type type) : type(type), role(PieceRole.KNIGHT) {};
    bool isValidMove(const IPoint &src, const IPoint &dst) override;
};

class Rook : public Piece {
 public:
    Rook(Type type) : type(type), role(PieceRole.ROOK) {};
    bool isValidMove(const IPoint &src, const IPoint &dst) override;
};

class Pawn : public Piece {
 public:
    Pawn(Type type) : type(type), role(PieceRole.PAWN) {};
    bool isValidMove(const IPoint &src, const IPoint &dst) override;
};

}  // namespace core
}  // namespace collapse

#endif  // COLLAPSE_CORE_PIECES_H_
