#include "collapse/core.h"
#include "collapse/core/pieces.h"

namespace collapse {
namespace core {

bool
Knight::isValidMove(const IMap &map, const IPoint &src, const IPoint &dst) override
{
    // check the L case, either x or y must be 1 or 2, but not the same
    if ((dst.getX() - src.getX() + dst.getY() - src.getY()) == 3)
        return true;

    return false;
}

}  // namespace core
}  // namespace collapse

