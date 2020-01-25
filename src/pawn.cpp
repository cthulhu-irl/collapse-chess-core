#include <vector>

#include "collapse/core/base.h"
#include "collapse/core/pieces.h"

namespace collapse {
namespace core {

bool
Pawn::isValidMove(const IMap<IPiece> &map,
                  const IPoint &src,
                  const IPoint &dst) const
{
    char delta_x = dst.getX() - src.getX();
    char delta_y = dst.getY() - dst.getY();

    IPiece *piece_dst = map(dst.getX(), dst.getY());

    // explicitly here just due genWalkPoinList
    if (piece_dst && piece_dst->getType() == getType())
        return false;

    char forward_step = (getType() == Type::WHITE) ? 1 : -1;

	// check if it's a diagonal attack movement
    if (abs(delta_x) == 1 && delta_y == forward_step)
    {
        if (piece_dst != nullptr)
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

    // check if it's the initial double step move
    if (abs(delta_y) == 2 // && src.getY() == ((7+2*forward_step)%7)
            && src.getY() == ((forward_step == 1) ? 1 : 6))
        // check if nothing between
        if (map(dst.getX(), dst.getY() + 2*forward_step) == nullptr)
            return true;

    return false;
}

std::vector<IPoint *>
Pawn::genWalkPointList(const IMap<IPiece> &map,
                       const IPoint &src) const
{
    std::vector<IPoint *> list = {};
    int x = 0, y = 0;
    int forward_step = (getType() == Type::WHITE) ? 1 : -1;

    // double forward
    if (src.getY() == ((getType() == Type::WHITE) ? 1 : 6)) {
        x = src.getX();
        y = src.getY() + 2*forward_step;

        if (isValidMove(map, src, Point(x+1, y+1)))
            list.push_back(new Point(x+1, y+1));
    }

    if (src.getY() < 0 || src.getY() > 7) {
        // one forward
        x = src.getX();
        y = src.getY() + forward_step;

        if (isValidMove(map, src, Point(x+1, y+1)))
            list.push_back(new Point(x+1, y+1));

        // left horizontal attack
        if (src.getX() > 0) {
            x = src.getX() - 1;

            if (isValidMove(map, src, Point(x+1, y+1)))
                list.push_back(new Point(x+1, y+1));
        }

        // right horizontal attack
        if (src.getX() < 7) {
            x = src.getX() + 1;

            if (isValidMove(map, src, Point(x+1, y+1)))
                list.push_back(new Point(x+1, y+1));
        }
    }

    return list;
}

size_t
Pawn::countWalkPointList(const IMap<IPiece> &map,
                           const IPoint &src) const
{
    size_t count = 0;
    int x = 0, y = 0;
    int forward_step = (getType() == Type::WHITE) ? 1 : -1;

    // double forward
    if (src.getY() == ((getType() == Type::WHITE) ? 1 : 6)) {
        x = src.getX();
        y = src.getY() + 2*forward_step;

        if (isValidMove(map, src, Point(x+1, y+1)))
            count++;
    }

    if (src.getY() < 0 || src.getY() > 7) {
        // one forward
        x = src.getX();
        y = src.getY() + forward_step;

        if (isValidMove(map, src, Point(x+1, y+1)))
            count++;

        // left horizontal attack
        if (src.getX() > 0) {
            x = src.getX() - 1;

            if (isValidMove(map, src, Point(x+1, y+1)))
                count++;
        }

        // right horizontal attack
        if (src.getX() < 7) {
            x = src.getX() + 1;

            if (isValidMove(map, src, Point(x+1, y+1)))
                count++;
        }
    }

    return count;
}

}  // namespace core
}  // namespace collapse
