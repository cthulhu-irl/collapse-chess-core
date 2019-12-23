#include "collapse/core/base.h"

#include "collapse/core.h"

namespace collapse {
namespace core {

Board::Board(Map &map) : map(map)
{
    //
}

Board::~Board() override
{
    // nothing to do here
}

bool
Board::move(const IPoint &src, const IPoint &dst) override
{
    //
}

bool
Board::upgradeRankPawn(PieceRole role) override
{
    // check if last_rank_pawn points to a pawn
    // check if valid role, if so... make correspondig piece
    // replace piece with new piece
}

bool
Board::isValidMove(const IPoint &src, const IPoint &dst) override
{
    // 
}

Status
Board::check_map(const Map &map, Type self_type, bool assign=false)
{
    // 
}

}  // namespace core
}  // namespace collapse
