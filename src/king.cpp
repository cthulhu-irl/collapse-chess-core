#include <vector>

#include "collapse/core.h"
#include "collapse/core/pieces.h"

namespace collapse {
namespace core {

bool
King::isValidMove(const IMap<IPiece> &map,
                  const IPoint &src,
                  const IPoint &dst) const
{
    char delta_x = dst.getX() - src.getX();
    char delta_y = dst.getY() - src.getY();

    // explicitly here just due genWalkPointList
    IPiece *dst_piece = map(dst.getX(), dst.getY());
    if (dst_piece && dst_piece->getType() == getType())
        return false;

    // is it a castling move?
    // check if king is in its initial point
    if (src.getX() == 4 && (src.getY() % 7) == 0)
    {
        // check if selected destination is next to an initial rook
        if (abs(delta_x) == 2 && (dst.getY() % 7) == 0)
        {
            // check if there's an original rook near dest
            // another way:
            //      ((delta_x|1 & 0x81) + 6) & 7 => 0 || 7
            if (map((delta_x < 0) ? 0 : 7, dst.getY())
                    ->getRole() != PieceRole::ROOK)
                return false;

            // check if there aren't anything between
            char stepper = (abs(delta_x) + 1) - delta_x;
            if (map(dst.getX() - stepper, dst.getY()) != nullptr)
                return false;

            if (map(dst.getX() - stepper*2, dst.getY()) != nullptr)
                return false;

            return true;
        }
    }

    // OR is it only one block away?
    if (abs(delta_x) == 1 || abs(delta_y) == 1)
        return true;

    return false;
}

std::vector<IPoint *>
King::genWalkPointList(const IMap<IPiece> &map,
                        const IPoint &src) const
{
    std::vector<IPoint *> list;
    int x = src.getX(), y = 0;

    // mid top
    if (src.getY() < 7) {
        y = src.getY() + 1;

        if (isValidMove(map, src, Point(x+1, y+1)))
            list.push_back(new Point(x+1, y+1));
    }

    // mid bottom
    if (src.getY() > 0) {
        y = src.getY() - 1;

        if (isValidMove(map, src, Point(x+1, y+1)))
            list.push_back(new Point(x+1, y+1));
    }

    // right
    if (src.getX() < 7) {
        x = src.getX() + 1;
        y = src.getY();

        if (isValidMove(map, src, Point(x+1, y+1)))
            list.push_back(new Point(x+1, y+1));

        // top
        y += 1;
        if (y <= 7 && isValidMove(map, src, Point(x+1, y+1)))
            list.push_back(new Point(x+1, y+1));

        // bottom
        y -= 2;
        if (y >= 0 && isValidMove(map, src, Point(x+1, y+1)))
            list.push_back(new Point(x+1, y+1));
    }

    // left
    if (src.getX() > 0) {
        x = src.getX() - 1;
        y = src.getY();

        if (isValidMove(map, src, Point(x+1, y+1)))
            list.push_back(new Point(x+1, y+1));

        // top
        y += 1;
        if (y <= 7 && isValidMove(map, src, Point(x+1, y+1)))
            list.push_back(new Point(x+1, y+1));

        // bottom
        y -= 2;
        if (y >= 0 && isValidMove(map, src, Point(x+1, y+1)))
            list.push_back(new Point(x+1, y+1));
    }

    return list;
}

}  // namespace core
}  // namespace collapse
