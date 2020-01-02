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
    // A: LIMITED TIME!!! this is just a goddamn uni project!!!!
    // C: thus... gonna be **dependent** to `Queen`, `Bishop`, etc...
    IPiece *piece = nullptr;
    Type ptype = Type::WHITE;

    // check if last_rank_pawn points to a pawn
    if (!this->last_rank_pawn)
        return false;

    piece = this->map.get(this->last_rank_pawn->getX(),
                            this->last_rank_pawn->getY());
    if (!piece || piece->getRole() != PieceRole::PAWN) // :| || :o
        return false;

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
    // IPoint is not Point, x and y might be out of 0..7 range
    // make sure piece at src != nullptr
    // make sure point src != point dst
    // make sure piece type src != piece type at dst
    // check if that piece supports it
    // check if that move doesn't end up in CHECKMATE
    return true;
}

Status
Board::check_map(const IMap<IPiece> &map, Type side) const
{
    // scan the map and save the points
    // RANK: if the rows at y=0 and y=7 have any Pawn
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
    return Status::TURN;
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
