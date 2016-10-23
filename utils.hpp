#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include <string>
#include <algorithm>

template<class T>
inline void PRINT_ELEMENTS (const T &container, std::string prefix="")
{
    std::cout << std::endl << prefix;
    for_each(container.cbegin(), container.cend(), [](typename T::value_type const &it){std::cout << it << " ";});
    std::cout << std::endl;
}

template <class T>
inline void INSERT_ELEMENTS (T &container, int start, std::size_t n)
{

    for (; n > 0; --n)
    {
        container.insert(container.end(), start++);
    }
}


#endif // UTILS_HPP
