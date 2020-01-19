#ifndef COLLAPSE_CORE_PIECES_H_
#define COLLAPSE_CORE_PIECES_HPP

#include <vector>

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
    std::vector<IPoint> genWalkPointList(
                            const IMap<IPiece> &map,
                            const IPoint &src) const override;

    Type getType() const override { return type; }
    PieceRole getRole() const override { return role; }

    IPiece *clone() const override { return new King(*this); }
};

class Queen : public IPiece {
    Type type;
    PieceRole role;

 public:
    Queen(Type type) : type(type), role(PieceRole::QUEEN) {}
    bool isValidMove(const IMap<IPiece> &map,
                     const IPoint &src,
                     const IPoint &dst) const override;
    std::vector<IPoint> genWalkPointList(
                            const IMap<IPiece> &map,
                            const IPoint &src) const override;

    Type getType() const override { return type; }
    PieceRole getRole() const override { return role; }

    IPiece *clone() const override { return new Queen(*this); }
};

class Bishop : public IPiece {
    Type type;
    PieceRole role;

 public:
    Bishop(Type type) : type(type), role(PieceRole::BISHOP) {}
    bool isValidMove(const IMap<IPiece> &map,
                     const IPoint &src,
                     const IPoint &dst) const override;
    std::vector<IPoint> genWalkPointList(
                            const IMap<IPiece> &map,
                            const IPoint &src) const override;

    Type getType() const override { return type; }
    PieceRole getRole() const override { return role; }

    IPiece *clone() const override { return new Bishop(*this); }
};

class Knight : public IPiece {
    Type type;
    PieceRole role;

 public:
    Knight(Type type) : type(type), role(PieceRole::KNIGHT) {}
    bool isValidMove(const IMap<IPiece> &map,
                     const IPoint &src,
                     const IPoint &dst) const override;
    std::vector<IPoint> genWalkPointList(
                            const IMap<IPiece> &map,
                            const IPoint &src) const override;

    Type getType() const override { return type; }
    PieceRole getRole() const override { return role; }

    IPiece *clone() const override { return new Knight(*this); }
};

class Rook : public IPiece {
    Type type;
    PieceRole role;

 public:
    Rook(Type type) : type(type), role(PieceRole::ROOK) {}
    bool isValidMove(const IMap<IPiece> &map,
                     const IPoint &src,
                     const IPoint &dst) const override;
    std::vector<IPoint> genWalkPointList(
                            const IMap<IPiece> &map,
                            const IPoint &src) const override;

    Type getType() const override { return type; }
    PieceRole getRole() const override { return role; }

    IPiece *clone() const override { return new Rook(*this); }
};

class Pawn : public IPiece {
    Type type;
    PieceRole role;

 public:
    Pawn(Type type) : type(type), role(PieceRole::PAWN) {}
    bool isValidMove(const IMap<IPiece> &map,
                     const IPoint &src,
                     const IPoint &dst) const override;
    std::vector<IPoint> genWalkPointList(
                            const IMap<IPiece> &map,
                            const IPoint &src) const override;

    Type getType() const override { return type; }
    PieceRole getRole() const override { return role; }

    IPiece *clone() const override { return new Pawn(*this); }
};

}  // namespace core
}  // namespace collapse

#endif  // COLLAPSE_CORE_PIECES_H_
