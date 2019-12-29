#include "collapse/core.h"
#include "collapse/core/pieces.h"

namespace collapse {
namespace core {

bool
King::isValidMove(const IMap<IPiece> &map,
                  const IPoint &src,
                  const IPoint &dst) const
{
    /*
    // is it a castling move?
    // check if king is in its initial point
    if (src.getX() == 5 && (src.getY() % 8) <= 1)
    {
        // check if selected destination is next to an initial rook
        char delta_x = dst.getX() - src.getX();
        if (abs(delta_x) == 2 && (dst.getY() % 8) <= 1)
        {
            // check if there's an original rook near dest
            if (map[dst.getY()][delta_x < 0 ? 1 : 8]->getRole() != PieceRole.ROOK)
                return false;

            // check if there aren't anything between
            char stepper = (abs(delta_x) + 1) - delta_x; // or delta_x & 0x81
            if (map[dst.getY()][dst.getX() - stepper  ] == nullptr) return false;
            if (map[dst.getY()][dst.getX() - stepper*2] == nullptr) return false;

            return true;
        }
    }

    // OR is it only one block away?
    if ((dst.getX() - src.getX()) == 1 || (dst.getY() - src.getY()) == 1)
        return true;
    */

    return false;
}

}  // namespace core
}  // namespace collapse
