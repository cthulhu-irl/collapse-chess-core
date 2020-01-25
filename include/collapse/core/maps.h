#ifndef COLLAPSE_CORE_MAPS_H_
#define COLLAPSE_CORE_MAPS_H_

#include <array>

#include "collpase/core/base.h"
#include "collapse/core/pieces.h"

#define _TW Type::WHITE
#define _TB Type::BLACK

#define _NR(t) new Rook(t)
#define _NH(t) new Knight(t)
#define _NB(t) new Bishop(t)
#define _NQ(t) new Queen(t)
#define _NK(t) new King(t)
#define _NP(t) new Pawn(t)

#define DEFAULT_MAP std::array<std::array<IPiece *, 8>, 8> { \
        std::array<IPiece *, 8> \
        {_NR(_TW), _NH(_TW), _NB(_TW), _NQ(_TW) \
         _NK(_TW), _NB(_TW), _NH(_TW), _NR(_TW)} \
         \
        std::array<IPiece *, 8> \
        {_NP(_TW), _NP(_TW), _NP(_TW), _NP(_TW) \
         _NP(_TW), _NP(_TW), _NP(_TW), _NP(_TW)} \
         \
        std::array<IPiece *, 8> \
        {nullptr, nullptr, nullptr, nullptr \
         nullptr, nullptr, nullptr, nullptr} \
         \
        std::array<IPiece *, 8> \
        {nullptr, nullptr, nullptr, nullptr \
         nullptr, nullptr, nullptr, nullptr} \
         \
        std::array<IPiece *, 8> \
        {nullptr, nullptr, nullptr, nullptr \
         nullptr, nullptr, nullptr, nullptr} \
         \
        std::array<IPiece *, 8> \
        {nullptr, nullptr, nullptr, nullptr \
         nullptr, nullptr, nullptr, nullptr} \
         \
        std::array<IPiece *, 8> \
        {_NP(_TB), _NP(_TB), _NP(_TB), _NP(_TB) \
         _NP(_TB), _NP(_TB), _NP(_TB), _NP(_TB)} \
         \
        {_NR(_TB), _NH(_TB), _NB(_TB), _NQ(_TB) \
         _NK(_TB), _NB(_TB), _NH(_TB), _NR(_TB)} \
    }

#endif  // COLLAPSE_CORE_MAP_H_
