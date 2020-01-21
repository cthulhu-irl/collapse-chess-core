#include "collapse/core.h"
#include "collapse/core/pieces.h"

namespace collapse {
namespace core {

bool
Queen::isValidMove(const IMap<IPiece> &map,
                   const IPoint &src,
                   const IPoint &dst) const
{
	char delta_x = dst.getX() - src.getX();
    char delta_y = dst.getY() - src.getY();

    // check if either diagonal, vertical or horizontal linear
    if (!(abs(delta_x) == abs(delta_y)
          || delta_x == 0
          || delta_y == 0))
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

std::vector<IPoint *>
Queen::genWalkPointList(const IMap<IPiece> &map,
                        const IPoint &src) const
{
    std::vector<IPoint *> list;
    int x, y;
    int x_step, y_step;

    // x directions
    for (x_step = -1; x_step <= 1; x_step++)
    {
        // y directions
        for (y_step = -1; y_step <= 1; y_step++)
        {
            // each step in x_step,y_step direction
            for (x=src.getX()+x_step, y=src.getY()+y_step;
                    (0 <= x && x <= 7) && (0 <= y && y <= 7);
                    x += x_step, y += y_step)
            {
                // get the piece at x,y as dest if there is any
                const IPiece *piece = map(x, y);

                // add the point to list if no piece or opposite type
                if (!piece || piece->getType() != getType())
                    list.push_back(new Point(x+1, y+1));
                
                // if a piece was found, there's no point to continue
                if (piece) break;
            }
        }
    }

    return list;
}

}  // namespace core
}  // namespace collapse
