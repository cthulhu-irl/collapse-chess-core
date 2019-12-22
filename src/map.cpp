#include <array>
#include <initializer_list>

#include "collapse/core.h"

namespace collapse {
namespace core {

/// Initializes `table` as an empty map in heap.
Map::Map()
{
    //
}

/// Initializes map by making a copy of provided `init_table`.
Map::Map(std::array<std::array<IPiece, 8>, 8> &&init_table)
    : Map()
{
    //
}

/// Initializes map by creating corresponding Piece in place
/// of each PieceRole in provided `init_table`. (brace constructor)
Map::Map(std::initializer_list<std::array<PieceRole, 8>> init_table)
    : Map()
{
    //
}

/// A better way to access the elements.
/// This function (operator overload) return a row of table
/// as a mutable lvalue.
std::array<IPiece, 8> &Map::operator[](std::size_t index) override
{
    //
}

/// Destructor releases the memory used by `table`.
Map::~Map()
{
    //
}

}  // namespace core
}  // namespace collapse
