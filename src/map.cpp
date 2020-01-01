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
    this->table = new std::array<std::array<T*, 8>, 8> {
        //  A        B        C        D
        //  E        F        G        H
        std::array<T*, 8>
        {nullptr, nullptr, nullptr, nullptr,
         nullptr, nullptr, nullptr, nullptr}, // rank 1

        std::array<T*, 8>
        {nullptr, nullptr, nullptr, nullptr,
         nullptr, nullptr, nullptr, nullptr}, // rank 2

        std::array<T*, 8>
        {nullptr, nullptr, nullptr, nullptr,
         nullptr, nullptr, nullptr, nullptr}, // rank 3

        std::array<T*, 8>
        {nullptr, nullptr, nullptr, nullptr,
         nullptr, nullptr, nullptr, nullptr}, // rank 4

        std::array<T*, 8>
        {nullptr, nullptr, nullptr, nullptr,
         nullptr, nullptr, nullptr, nullptr}, // rank 5

        std::array<T*, 8>
        {nullptr, nullptr, nullptr, nullptr,
         nullptr, nullptr, nullptr, nullptr}, // rank 6

        std::array<T*, 8>
        {nullptr, nullptr, nullptr, nullptr,
         nullptr, nullptr, nullptr, nullptr}, // rank 7

        std::array<T*, 8>
        {nullptr, nullptr, nullptr, nullptr,
         nullptr, nullptr, nullptr, nullptr}, // rank 8
    };
}

/// Initializes map by making a **shallow* copy of 
/// provided `init_table`.
/// NOTE: this means `init_table` matrix is hard copied, but cell
///       pointers aren't hard copied.
template<typename T>
Map<T>::Map(const std::array<std::array<T*, 8>, 8> &init_table)
    : Map()
{
    for (std::size_t y=0; y < 8; y++) {
        for (std::size_t x=0; x < 8; x++) {
            (*this->table)[y][x] = init_table[y][x];
        }
    }
}

/// copy constructor
template<typename T>
Map<T>::Map(const Map<T> &other) : Map()
{
    // gonna be the same as copy assignment operator...
}

/// copy assignment operator
template<typename T>
Map<T> &
Map<T>::operator=(const Map<T> &other)
{
    if (this == &other)
        return *this;

    T *cell = nullptr;
    for (std::size_t y=0; y < 8; y++) {
        for (std::size_t x=0; x < 8; x++) {
            cell = (*other.table)[y][x];

            if (cell != nullptr)
                cell = cell->clone();

            (*this->table)[y][x] = cell;
        }
    }

    return *this;
}

/// Destructor releases the memory used by `table`.
template<typename T>
Map<T>::~Map()
{
    // free all cells and set them to nullptr after free
    // free the table and set it to nullptr
}

/// A better way to access the elements.
/// This function (operator overload) return a row of table
/// as a mutable lvalue.
template<typename T>
T *
Map<T>::operator()(std::size_t x, std::size_t y) const
{
    return this->get(x, y);
}

/// returns the cell at x,y position if the table exists,
/// otherwise it returns nullptr.
template<typename T>
T *
Map<T>::get(std::size_t x, std::size_t y) const
{
    if (this->table)
        return (*this->table)[y][x];

    return nullptr;
}

/// set the cell at x,y position to ptr if table exists.
template<typename T>
T *
Map<T>::set(std::size_t x, std::size_t y, T *ptr)
{
    // check if table exists
    if (!this->table)
        return nullptr;

    // get the cell for further checks
    T *cell = (*this->table)[y][x];
    
    // if cell and ptr are the same, nothing to do
    if (ptr == cell)
        return ptr;

    // if cell is not nullptr, free it
    if (cell != nullptr)
        delete cell;

    // assign ptr to the place
    (*this->table)[y][x] = ptr;

    return ptr;
}

/// delete the cell at x,y position by freeing its memory
/// and then set it to nullptr
template<typename T>
T *
Map<T>::delete_at(std::size_t x, std::size_t y)
{
    // check if table exists
    if (!this->table)
        return nullptr;

    T *cell = (*this->table)[y][x];

    // check if cell be not nullptr
    if (cell == nullptr)
        return nullptr;

    // free the memory, assign the nullptr
    delete cell;
    (*this->table)[y][x] = nullptr;

    return nullptr;
}

}  // namespace core
}  // namespace collapse
