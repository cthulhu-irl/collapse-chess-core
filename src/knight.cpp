#include <vector>

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

std::vector<IPoint *>
Knight::genWalkPointList(const IMap<IPiece> &map,
                         const IPoint &src) const
{
    std::vector<IPoint *> list = {};
    int x = src.getX(), y = 0;

    // top-*-top
    if (src.getY() < 6) {
        y = src.getY() + 2;

        // top-left-top
        if (src.getX() < 7 && isValidMove(map, src, Point(x+1, y)))
            list.push_back(new Point(x+1, y));

        // top-right-top
        if (src.getX() > 0 && isValidMove(map, src, Point(x-1, y)))
            list.push_back(new Point(x-1, y));
    }

    // bot-*-bot
    if (src.getY() > 1) {
        y = src.getY() - 2;

        // bot-left-bot
        if (src.getX() < 7 && isValidMove(map, src, Point(x+1, y)))
            list.push_back(new Point(x+1, y));

        // bot-right-bot
        if (src.getX() > 0 && isValidMove(map, src, Point(x-1, y)))
            list.push_back(new Point(x-1, y));
    }

    // top-*-bot
    if (src.getY() < 7) {
        y = src.getY() + 1;

        // top-left-bot
        if (src.getX() < 6 && isValidMove(map, src, Point(x+2, y)))
            list.push_back(new Point(x+2, y));

        // top-right-bot
        if (src.getX() > 1 && isValidMove(map, src, Point(x-2, y)))
            list.push_back(new Point(x-2, y));
    }

    // bot-*-top
    if (src.getY() > 0) {
        y = src.getY() - 1;

        // bot-left-top
        if (src.getX() < 6 && isValidMove(map, src, Point(x+2, y)))
            list.push_back(new Point(x+2, y));

        // bot-right-top
        if (src.getX() > 1 && isValidMove(map, src, Point(x-2, y)))
            list.push_back(new Point(x-2, y));
    }

    return list;
}

}  // namespace core
}  // namespace collapse
