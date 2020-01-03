#include <memory>
#include <vector>

#include "collapse/core/base.h"

#include "collapse/core.h"
#include "collapse/core/pieces.h" // unfortuanately

namespace collapse {
namespace core {

Board::Board(Map<IPiece> &map)
{
    this->map = map;
    this->status = Status::TURN;
    this->last_rank_pawn = nullptr;
}

bool
Board::move(const IPoint &src, const IPoint &dst)
{
    // check if it's a valid move
    if (!this->isValidMove(src, dst))
        return false;

    // replace piece at destination with piece at src
    this->map.move_from_to(src.getX(), src.getY(),
                               dst.getX(), dst.getY(), false);

    return true;
}

bool
Board::upgradeRankPawn(PieceRole role)
{
    // Q: think of FactoryPattern and dependency injection?
    // A: LIMITED TIME!!! and this is just a goddamn uni project!!!!
    // C: thus... gonna be **dependent** to `Queen`, `Bishop`, etc...
    IPiece *piece = nullptr;
    Type ptype = Type::WHITE;

    // check if last_rank_pawn points to a pawn
    if (!this->last_rank_pawn)
        return false;

    piece = this->map.get(this->last_rank_pawn->getX(),
                            this->last_rank_pawn->getY());
    ptype = piece->getType();

    // check if valid role, if so... make correspondig piece
    switch (role) {
        case PieceRole::QUEEN:  piece = new Queen(ptype); break;
        case PieceRole::BISHOP: piece = new Bishop(ptype); break;
        case PieceRole::ROOK:   piece = new Rook(ptype); break;
        case PieceRole::KNIGHT: piece = new Knight(ptype); break;
        default:
            // only those 4 pieces are supported...
            return false;
    }

    // set the the new piece in map
    piece = this->map.set(this->last_rank_pawn->getX(),
                            this->last_rank_pawn->getY(),
                            piece);
    if (!piece)
        return false;

    // unset the last_rank_pawn (set it to nullptr)
    this->last_rank_pawn = nullptr;

    return true;
}

bool
Board::isValidMove(const IPoint &src, const IPoint &dst) const
{
    // we'll need these later
    IPiece *piece_src = this->map(src.getX(), src.getY());
    IPiece *piece_dst = this->map(dst.getX(), dst.getY());

    // make sure piece at src != nullptr
    if (!piece_src)
        return false;

    // make sure point src != point dst
    if (src != dst)
        return false;

    // make sure piece type src != piece type at dst
    if (piece_dst && piece_src->getType() == piece_dst->getType())
        return false;

    // check if that piece supports it
    if (!piece_src->isValidMove(this->map, src, dst))
        return false;

    // TODO check if that move doesn't end up in CHECKMATE

    return true;
}

Status
Board::checkMap(const IMap<IPiece> &map, Type side) const
{
    Status ret = Status::TURN;
    // RANK: if the rows at y=0 and y=7 have any Pawn

    // scan the map and save the points
    std::vector<IPoint *> this_side;
    std::vector<IPoint *> other_side;
    IPoint *this_king = nullptr;
    IPoint *other_king = nullptr;

    for (size_t y=0; y < 8; y++) {
        for (size_t x=0; x < 8; x++) {
            IPiece *piece = this->map(x, y);
            if (!piece)
                continue;

            IPoint *point = new Point(x, y);

            if (piece->getType() == side) {
                if (!this_king && piece->getRole() == PieceRole::KING)
                    this_king = point;

                this_side.push_back(point);
            }
            else {
                if (!other_king && piece->getRole() == PieceRole::KING)
                    other_king = point;

                other_side.push_back(point);
            }

        }
    }

    // CHECK & CHECKMATE:
    // if the king is NOT safe it can be check or checkmate
        // CHECKMATE
        // if there isn't anything threatening king, return CHECK
        // otherwise there are 3 ways NOT to be checkmate
        // 1. if king has a move that doesn't end up another check
        // 2. if there is only one threatening piece and there is
        // another piece of this `side` threatening it
        // otherwise it's definitely a CHECK
    // STALEMATE:
        // no idea for STALEMATE for now...
    return ret;
}

const IPoint *
Board::getLastRankPawn() const
{
    return this->last_rank_pawn;
}

Status
Board::getStatus() const
{
    return this->status;
}

}  // namespace core
}  // namespace collapse
