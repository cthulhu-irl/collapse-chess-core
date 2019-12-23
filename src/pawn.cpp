#include "collapse/core/base.h"
#include "collapse/core/pieces.h"

namespace collapse {
namespace core {

bool
Pawn::isValidMove(const IMap &map, const IPoint &src, const IPoint &dst) override
{
    char delta_x = dst.getX() - src.getX();
    char delta_y = dst.getY() - dst.getY();
    
    IPiece *piece_dst = map[dst.getY()-1][dst.getX()-1];
    IPiece *piece_src = map[src.getY()-1][src.getY()-1];

    char forward_step = (piece_src->getType() == Type.WHITE) ? 1 : -1;

	// check if it's a diagonal attack movement
    if (abs(delta_x) == 1 && delta_y == forward_step)
    {
        if (piece_dst != nullptr && piece_dst->getType() != piece_src->getType())
            return true;

        return false;
    }

    // check if dst is on the same X-axis
    if (delta_x != 0)
        return false;

    // check if nothing at dst
    if (piece_dst != nullptr)
        return false;

    // check if it's the normal one block move
    if (delta_y == forward_step)
        return true;

    // check if it's the first double forward intial move
    if (delta_y == 2 * forward_step && src.getY() == (forward_step == 1 ? 2 : 6))
        // check if nothing between
        if (map[dst.getY() + 2*forward_step - 1][dst.getX()-1] == nullptr)
            return true;

    return false;
}

}  // namespace core
}  // namespace collapse

