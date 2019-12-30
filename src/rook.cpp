#include "collapse/core.h"
#include "collapse/core/pieces.h"

namespace collapse {
namespace core {

bool
Rook::isValidMove(const IMap<IPiece> &map,
                  const IPoint &src,
                  const IPoint &dst) const
{
	char delta_x = dst.getX() - src.getX();
    char delta_y = dst.getY() - src.getY();

    // check if either vertical or horizontal linear
    if (delta_x != 0 && delta_y != 0)
        return false;

    // check if nothing between
    char x_step = (delta_x == 0) ? 0 : (delta_x < 0) ? -1 : 1;
    char y_step = (delta_y == 0) ? 0 : (delta_y < 0) ? -1 : 1;

    char x_end = dst.getX();
    char y_end = dst.getY();

    for (char x = src.getX() + x_step, y = src.getY() + y_step;
            x != x_end || y != y_end;
            x += x_step, y += y_step)
    {
        if (map(x, y) != nullptr)
            return false;
    }

    return true;
}

}  // namespace core
}  // namespace collapse
