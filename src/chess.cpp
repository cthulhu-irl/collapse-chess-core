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
    if (player != this->state.player)
        return this->state;

    // make the move if agrees
    if (!(this->board.move(src, dst)))
        return this->state;

    // update state
    if (this->state.player == this->player_white)
        this->state.player = this->player_black;
    else
        this->state.player = this->player_white;

    this->state.status = this->board.getStatus();

    return this->state;
}

const IState &
Chess::rank(const IPlayer &player, PieceRole role)
{
    // is it the rank status?
    if (this->state.status != Status::RANK)
        return this->state;

    // is the current player?
    if (player != this->state.player)
        return this->state;

    // update if board agrees
    if (!(this->board.upgradeRankPawn(role)))
        return this->state;

    // update the state
    if (this->state.player == this->player_white)
        this->state.player = this->player_black;
    else
        this->state.player = this->player_white;

    this->state.status = this->board.getStatus();

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
