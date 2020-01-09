#include "collapse/core/base.h"

#include "collapse/core.h"

namespace collapse {
namespace core {

Chess::Chess(IPlayer &white, IPlayer &black, Map<IPiece> &map)
    : board(Board(map))
    , state(this->player_white, Status::TURN)
    , player_black(black)
    , player_white(white)
    , map_init(map)
{
    //
}

const IState &
Chess::move(const IPlayer &player,
            const IPoint &src,
            const IPoint &dst)
{
    //
    return this->state;
}

const IState &
Chess::rank(const IPlayer &player, PieceRole role)
{
    //
    return this->state;
}

const IState &
Chess::fold(const IPlayer &player)
{
    //
    return this->state;
}

const IState &
Chess::reset()
{
    //
    return this->state;
}

const IState &
Chess::redo()
{
    //
    return this->state;
}

const IState &
Chess::undo()
{
    //
    return this->state;
}

const IState &
Chess::getState() const
{
    //
    return this->state;
}

}  // namespace core
}  // namespace collapse
