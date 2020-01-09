#ifndef STACK_LIST_H_
#define STACK_LIST_H_

#include <vector>

template<typename T>
class StackList {
    std::vector<T> m_list;
    int m_cursor;

 public:
    StackList();

    T &push(T item);
    T pop();

    T &next();
    T &prev();
};

#endif  // STACK_LIST_H_
