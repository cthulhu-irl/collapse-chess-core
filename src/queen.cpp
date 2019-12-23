#include "collapse/core.h"
#include "collapse/core/pieces.h"

namespace collapse {
namespace core {

bool
Queen::isValidMove(const IMap &map, const IPoint &src, const IPoint &dst) override
{
	char delta_x = dst.getX() - src.getX();
    char delta_y = dst.getY() - src.getY();

    // check if either diagonal, vertical or horizontal linear
    if (delta_x == delta_y || delta_x == 0 || delta_y == 0)
        return false;

    // check if nothing between
    char x_step = delta_x & 0x71, y_step = delta_y & 0x71;
    char x_end = dst.getX(), y_end = dst.getY();

    for (char x = src.getX() + x_step - 1, y = src.getY() + y_step - 1;
            x != x_end || y != y_end;
            (x += x_step) & (y += y_step))
    {
        if (map[y][x] != nullptr)
            return false;
    }
}

}  // namespace core
}  // namespace collapse
