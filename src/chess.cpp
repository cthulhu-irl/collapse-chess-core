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
    // update the state's status
    state.status = this->board.getStatus();
}

const IState &
Chess::move(const IPlayer &player,
            const IPoint &src,
            const IPoint &dst)
{
    // is it the current player?
    // is it a valid move?
    // make the move
    // update state
    return this->state;
}

const IState &
Chess::rank(const IPlayer &player, PieceRole role)
{
    // is the current player?
    // update if board agrees
    // update the state
    return this->state;
}

const IState &
Chess::fold(const IPlayer &player)
{
    // is the current player?
    // update the state
    return this->state;
}

const IState &
Chess::reset()
{
    // reset the board
    // update the state
    return this->state;
}

bool
Chess::isValidMove(const IPlayer &player,
                     const IPoint &src,
                     const IPoint &dst) const
{
    // is it the current player?
    // does board agree with the move?
    return false;
}

const IState &
Chess::getState() const
{
    return this->state;
}

}  // namespace core
}  // namespace collapse
