#include <array>
#include <initializer_list>

#include "collapse/core/base.h"
#include "collapse/core.h"

namespace collapse {
namespace core {

/// Initializes `table` as an empty map in heap.
template<typename T>
Map<T>::Map()
{
    //
}

/// Initializes map by making a copy of provided `init_table`.
template<typename T>
Map<T>::Map(std::array<std::array<T, 8>, 8> &&init_table)
    : Map()
{
    //
}

/// A better way to access the elements.
/// This function (operator overload) return a row of table
/// as a mutable lvalue.
template<typename T>
T *Map<T>::operator()(std::size_t x, std::size_t y) const
{
    //
    return nullptr;
}

/// Destructor releases the memory used by `table`.
template<typename T>
Map<T>::~Map()
{
    //
}

}  // namespace core
}  // namespace collapse
