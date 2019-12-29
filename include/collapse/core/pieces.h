#ifndef COLLAPSE_CORE_PIECES_H_
#define COLLAPSE_CORE_PIECES_HPP

#include "collapse/core/base.h"
#include "collapse/core.h"

namespace collapse {
namespace core {

class King : public IPiece {
    Type type;
    PieceRole role;

 public:
    King(Type type) : type(type), role(PieceRole::KING) {}
    bool isValidMove(const IMap<IPiece> &map,
                     const IPoint &src,
                     const IPoint &dst) const override;

    Type getType() const override { return type; }
    PieceRole getRole() const override { return role; }
};

class Queen : public IPiece {
    Type type;
    PieceRole role;

 public:
    Queen(Type type) : type(type), role(PieceRole::QUEEN) {}
    bool isValidMove(const IMap<IPiece> &map,
                     const IPoint &src,
                     const IPoint &dst) const override;

    Type getType() const override { return type; }
    PieceRole getRole() const override { return role; }
};

class Bishop : public IPiece {
    Type type;
    PieceRole role;

 public:
    Bishop(Type type) : type(type), role(PieceRole::BISHOP) {}
    bool isValidMove(const IMap<IPiece> &map,
                     const IPoint &src,
                     const IPoint &dst) const override;

    Type getType() const override { return type; }
    PieceRole getRole() const override { return role; }
};

class Knight : public IPiece {
    Type type;
    PieceRole role;

 public:
    Knight(Type type) : type(type), role(PieceRole::KNIGHT) {}
    bool isValidMove(const IMap<IPiece> &map,
                     const IPoint &src,
                     const IPoint &dst) const override;

    Type getType() const override { return type; }
    PieceRole getRole() const override { return role; }
};

class Rook : public IPiece {
    Type type;
    PieceRole role;

 public:
    Rook(Type type) : type(type), role(PieceRole::ROOK) {}
    bool isValidMove(const IMap<IPiece> &map,
                     const IPoint &src,
                     const IPoint &dst) const override;

    Type getType() const override { return type; }
    PieceRole getRole() const override { return role; }
};

class Pawn : public IPiece {
    Type type;
    PieceRole role;

 public:
    Pawn(Type type) : type(type), role(PieceRole::PAWN) {}
    bool isValidMove(const IMap<IPiece> &map,
                     const IPoint &src,
                     const IPoint &dst) const override;

    Type getType() const override { return type; }
    PieceRole getRole() const override { return role; }
};

}  // namespace core
}  // namespace collapse

#endif  // COLLAPSE_CORE_PIECES_H_
