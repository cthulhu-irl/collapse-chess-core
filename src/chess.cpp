#include "collapse/core/base.h"

#include "collapse/core.h"

namespace collapse {
namespace core {

Chess::Chess(const IPlayer &white, const IPlayer &black, const IMap &map)
{
    //
}

const IState &
Chess::move(const IPlayer &player, const IPoint &src, const IPoint &dst)
{
    //
}

const IState &
Chess::rank(const IPlayer &player, PieceRole role)
{
    //
}

const IState &
Chess::fold(const IPlayer &player)
{
    //
}

const IState &
Chess::reset()
{
    //
}

const IState &
getState()
{
    //
}

}  // namespace core
}  // namespace collapse
