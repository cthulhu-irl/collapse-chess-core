#include "collapse/core/base.h"
#include "collapse/core/pieces.h"
#include "collapse/core.h"

namespace collapse {
namespace core {

bool
Knight::isValidMove(const IMap<IPiece> &map,
                    const IPoint &src,
                    const IPoint &dst) const
{
    char delta_x = dst.getX() - src.getX();
    char delta_y = dst.getY() - src.getY();

    // check the L case,
    // either x or y must be 1 or 2, but not the same
    if (abs(delta_x) == 1 && abs(delta_y) == 2)
        return true;

    if (abs(delta_x) == 2 && abs(delta_y) == 1)
        return true;

    return false;
}

}  // namespace core
}  // namespace collapse
