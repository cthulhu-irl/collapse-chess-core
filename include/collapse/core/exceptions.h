#ifndef COLLAPSE_CORE_EXCEPTIONS_H_
#define COLLAPSE_CORE_EXCEPTIONS_H_

#include <exception>

class PointInvalidRange : public std::exception {

    const char *what() const throw()
    {
        return "either x or y are not in range 1..8 (or y: a..h)";
    }

};

#endif  // COLLAPSE_CORE_EXCEPTIONS_H_
