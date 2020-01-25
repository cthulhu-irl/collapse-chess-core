#include <memory>
#include <vector>

#include "collapse/core/base.h"

#include "collapse/core.h"
#include "collapse/core/pieces.h" // unfortuanately

namespace collapse {
namespace core {

Board::Board(Map<IPiece> &map)
{
    this->map = map;
    this->last_rank_pawn = nullptr;
    this->status = this->checkMap(map, Type::WHITE);
}

bool
Board::move(const IPoint &src, const IPoint &dst)
{
    // check if it's a valid move
    if (!this->isValidMove(src, dst))
        return false;

    // replace piece at destination with piece at src
    IPiece *piece = this->map.move_from_to(src.getX(), src.getY(),
                                    dst.getX(), dst.getY(), false);
    if (!piece)
        return false;

    // update status
    this->status = this->checkMap(this->map, piece->getType());

    return true;
}

bool
Board::upgradeRankPawn(PieceRole role)
{
    IPiece *piece = nullptr;
    Type ptype = Type::WHITE;

    // check if last_rank_pawn points to a pawn
    if (!this->last_rank_pawn)
        return false;

    piece = this->map.get(this->last_rank_pawn->getX(),
                            this->last_rank_pawn->getY());
    ptype = piece->getType();

    // check if valid role, if so... make correspondig piece
    switch (role) {
        case PieceRole::QUEEN:  piece = new Queen(ptype); break;
        case PieceRole::BISHOP: piece = new Bishop(ptype); break;
        case PieceRole::ROOK:   piece = new Rook(ptype); break;
        case PieceRole::KNIGHT: piece = new Knight(ptype); break;
        default:
            // only those 4 pieces are supported...
            return false;
    }

    // set the the new piece in map
    piece = this->map.set(this->last_rank_pawn->getX(),
                            this->last_rank_pawn->getY(),
                            piece);
    if (!piece)
        return false;

    // unset the last_rank_pawn (set it to nullptr)
    this->last_rank_pawn = nullptr;

    // update status
    this->status = this->checkMap(this->map, ptype);

    return true;
}

bool
Board::isValidMove(const IPoint &src, const IPoint &dst) const
{
    // make sure point src != point dst
    if (src == dst)
        return false;

     // we'll need these later
    IPiece *piece_src = this->map(src.getX(), src.getY());
    IPiece *piece_dst = this->map(dst.getX(), dst.getY());

    // make sure piece at src != nullptr
    if (!piece_src)
        return false;

   // make sure piece type src != piece type at dst
    if (piece_dst && piece_src->getType() == piece_dst->getType())
        return false;

    // check if that piece supports it
    if (!piece_src->isValidMove(this->map, src, dst))
        return false;

    // fallback return value
    bool ret_val = true;

    // take a temporary map copy
    IMap<IPiece> *tmap = new Map<IPiece>;
    *tmap = map;

    // simulate the move
    tmap->move_from_to(src.getX(), src.getY(),
                            dst.getX(), dst.getY(), false);

    // check if the move doesn't end up in CHECK or CHECKMATE
    Status next_status = checkMap(*tmap, piece_src->getType());
    if (next_status == Status::CHECK
            && next_status == Status::CHECKMATE)
        ret_val = false;

    // clean up
    delete tmap;

    return ret_val;
}

Status
Board::checkMap(const IMap<IPiece> &map, Type side) const
{
    Status ret = Status::TURN;
    IPiece *piece = nullptr;

    // RANK: if the rows at y=0 and y=7 have any Pawn
    // scan the map and save the points
    std::vector<IPoint *> this_side;
    std::vector<IPoint *> other_side;
    IPoint *this_king = nullptr;
    IPoint *other_king = nullptr;

    for (size_t y=0; y < 8; y++) {
        for (size_t x=0; x < 8; x++) {
            piece = this->map(x, y);
            if (!piece)
                continue;

            IPoint *point = new Point(x, y);

            if (piece->getType() == side) {
                if (!this_king
                        && piece->getRole() == PieceRole::KING)
                    this_king = point;

                this_side.push_back(point);
            }
            else {
                if (!other_king
                        && piece->getRole() == PieceRole::KING)
                    other_king = point;

                other_side.push_back(point);
            }

            if ((y % 7 == 0) && piece->getRole() == PieceRole::PAWN)
            {
                ret = Status::RANK;
                break;
            }
        }

        if (ret != Status::TURN)
            break;
    }

    if (ret == Status::TURN) {
        // CHECK
        if (isCheck(map, side, this_side, other_side,
                                    *this_king, *other_king))
        {
            ret = Status::CHECK;

            // CHECKMATE
            if (isCheckMate(map, side, this_side, other_side,
                                    *this_king, *other_king, false))
                ret = Status::CHECKMATE;
        }

        // STALEMATE
        else {
            // check if there are any possible movement
            // for king that doesn't end up checkmate
            std::vector<IPoint *> this_single_side = {this_king};
            piece = map(this_king->getX(), this_king->getY());

            std::vector<IPoint *> king_moves =
                            piece->genWalkPointList(map, *this_king);

            IMap<IPiece> *tmap = new Map<IPiece>;
            bool has_king_moves = false;

            for (auto move_point : king_moves) {
                *tmap = map;

                // temporary movement
                tmap->move_from_to(
                            this_king->getX(), this_king->getY(),
                            move_point->getX(), move_point->getY(),
                            false);

                // doesn't the move fall in checkmate?
                // no point to check more, if a move has been found
                if (!has_king_moves &&
                        !isCheckMate(*tmap, side, this_single_side,
                                        other_side, *this_king,
                                        *other_king, false))
                {
                    has_king_moves = true;
                }

                // clean up
                delete move_point;
            }

            // clean up
            delete tmap;

            // check if other piece have any possible move
            if (!has_king_moves) {
                bool has_others_moves = false;

                for (auto point : this_side) {
                    // no the king, we have checked that
                    // in proper way
                    if (*point == *this_king)
                        continue;

                    piece = map(point->getX(), point->getY());

                    if (piece->countWalkPointList(map, *point)) {
                        has_others_moves = true;
                        break;
                    }
                }

                // there aren't any other piece moves?
                if (!has_others_moves)
                    ret = Status::STALEMATE;
            }
        }
    }

    // clean up
    for (auto iter=this_side.begin();
            iter != this_side.end();
            iter++)
        delete *iter;

    for (auto iter=other_side.begin();
            iter != other_side.end();
            iter++)
        delete *iter;

    return ret;
}

bool
Board::isCheck(const IMap<IPiece> &map,
                Type side,
                const std::vector<IPoint *> &this_pieces,
                const std::vector<IPoint *> &other_pieces,
                const IPoint &this_king,
                const IPoint &other_king) const
{
    // for each piece at other_pieces (opposite side's pieces)
    for (auto point_iter = other_pieces.cbegin();
                point_iter != other_pieces.cend();
                point_iter++)
    {
        // check if they threat this side's king
        auto piece = map((*point_iter)->getX(),
                            (*point_iter)->getY());
        if (piece->isValidMove(map, **point_iter, this_king))
            return true;
    }

    return false;
}

bool
Board::isCheckMate(const IMap<IPiece> &map,
                    Type side,
                    const std::vector<IPoint *> &this_pieces,
                    const std::vector<IPoint *> &other_pieces,
                    const IPoint &this_king,
                    const IPoint &other_king,
                    const bool recheck) const
{
    // if recheck, then check if map is already in CHECK state
    if (recheck && !isCheck(map, side, this_pieces, other_pieces,
                                this_king, other_king))
        return false;

    // make a copy of map for further uses (temporary map)
    IMap<IPiece> *tmap = new Map<IPiece>;

    std::vector<IPoint *> moves;
    IPoint *src;
    IPoint *dst;
    IPiece *piece;
    bool is_checkmate = false;

    // check if any of this_pieces have a move that gets
    // this_king out of threat
    for (auto point_iter=this_pieces.cbegin();
                point_iter != this_pieces.cend() && !is_checkmate;
                point_iter++)
    {
        src = *point_iter;
        piece = map(src->getX(), src->getY());
        if (!piece) continue;

        moves = piece->genWalkPointList(map, *src);

        // for each possible movements piece at point_iter can have
        for (auto move_iter=moves.cbegin();
                    move_iter != moves.cend() && !is_checkmate;
                    move_iter++)
        {
            // re/set the temp map and destination
            *tmap = map;
            dst = *move_iter;

            // make the move
            tmap->move_from_to(src->getX(), src->getY(),
                                dst->getX(), dst->getY(), false);

            // does the move end up in check?
            for (auto other_iter = other_pieces.cbegin();
                        other_iter != other_pieces.cend();
                        other_iter++)
            {
                // make sure this opposite piece isn't destroyed
                // in temp map
                if (**other_iter == *dst)
                    continue;

                // check if they threat this side's king
                auto other_point = *other_iter;
                auto other_piece = tmap->get(other_point->getX(),
                                                other_point->getY());

                if (other_piece->isValidMove(*tmap,
                                        *other_point, this_king))
                {
                    is_checkmate = true;
                    break;
                }
            }
        }

        // clean up the moves
        for (auto iter=moves.begin(); iter != moves.end(); iter++)
            if (*iter)
                delete *iter;
    }

    // clean up
    if (tmap)
        delete tmap;

    return is_checkmate;
}

const IPoint *
Board::getLastRankPawn() const
{
    return this->last_rank_pawn;
}

Status
Board::getStatus() const
{
    return this->status;
}

}  // namespace core
}  // namespace collapse
