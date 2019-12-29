#include "collapse/core/base.h"

#include "collapse/core.h"

namespace collapse {
namespace core {

Board::Board(Map<IPiece> &map) : last_rank_pawn({0, 0})
{
    this->map = map;
    this->status = Status::TURN;
    this->has_last_rank_pawn = false;
}

bool
Board::move(const IPoint &src, const IPoint &dst)
{
    //
    return false;
}

bool
Board::upgradeRankPawn(PieceRole role)
{
    // check if last_rank_pawn points to a pawn
    // check if valid role, if so... make correspondig piece
    // replace piece with new piece
    return false;
}

bool
Board::isValidMove(const IPoint &src, const IPoint &dst) const
{
    // 
    return false;
}

Status
Board::check_map(const IMap<IPiece> &map, Type self_type) const
{
    // 
    return Status::TURN;
}

IPoint *
Board::getLastRankPawn() const
{
    //
    return nullptr;
}

}  // namespace core
}  // namespace collapse
