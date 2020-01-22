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

    // explicitly here just due genWalkPoinList
    IPiece *dst_piece = map(dst.getX(), dst.getY());
    if (dst_piece && dst_piece->getType() == getType())
        return false;

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

    // NOTE: +1s are for offset sanitization,
    //       and are left explicit to be clear.

    // top-*-top
    if (src.getY() < 6) {
        y = src.getY() + 2;

        // top-right-top
        if (src.getX() < 7
                && isValidMove(map, src, Point(x+1+1, y+1)))
            list.push_back(new Point(x+1, y));

        // top-left-top
        if (src.getX() > 0
                && isValidMove(map, src, Point(x-1+1, y+1)))
            list.push_back(new Point(x-1, y));
    }

    // bot-*-bot
    if (src.getY() > 1) {
        y = src.getY() - 2;

        // bot-right-bot
        if (src.getX() < 7
                && isValidMove(map, src, Point(x+1+1, y+1)))
            list.push_back(new Point(x+1+1, y+1));

        // bot-left-bot
        if (src.getX() > 0
                && isValidMove(map, src, Point(x-1+1, y+1)))
            list.push_back(new Point(x-1+1, y+1));
    }

    // top-*-bot
    if (src.getY() < 7) {
        y = src.getY() + 1;

        // top-right-bot
        if (src.getX() < 6
                && isValidMove(map, src, Point(x+2+1, y+1)))
            list.push_back(new Point(x+2+1, y+1));

        // top-left-bot
        if (src.getX() > 1
                && isValidMove(map, src, Point(x-2+1, y+1)))
            list.push_back(new Point(x-2+1, y+1));
    }

    // bot-*-top
    if (src.getY() > 0) {
        y = src.getY() - 1;

        // bot-right-top
        if (src.getX() < 6
                && isValidMove(map, src, Point(x+2+1, y+1)))
            list.push_back(new Point(x+2+1, y+1));

        // bot-left-top
        if (src.getX() > 1
                && isValidMove(map, src, Point(x-2+1, y+1)))
            list.push_back(new Point(x-2+1, y+1));
    }

    return list;
}

}  // namespace core
}  // namespace collapse
