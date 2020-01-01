#include "collapse/core/base.h"

#include "collapse/core.h"

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
    // check if last_rank_pawn points to a pawn
    // check if valid role, if so... make correspondig piece
    // set the the new piece in map
    // unset the has_last_rank_pawn and last_rank_pawn
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
    // CHECK & CHECKMATE
    // if the king is NOT safe it can be check or checkmate
        // CHECKMATE
        // if there isn't anything threatening king, return CHECK
        // otherwise there are 3 ways NOT to be checkmate
        // 1. if king has a move that doesn't end up another check
        // 2. if there is only one threatening piece and there is
        // another piece of this `side` threatening it
        // otherwise it's definitely a CHECK
    // STALEMATE
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
