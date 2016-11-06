#ifndef STD_SORT_H
#define STD_SORT_H

#include <utility>
#include <iterator>

template <typename I>
I find_its_place(I first, I last)
{
    if (first == last)
        return last;
    else
        --last;
    while (first != last)
    {
        if (std::distance(first, last) > 0)
        {
            if (*last < *first)
            {
                std::swap(*first, *last);
                std::swap(first, last);
                ++last;
            }
            else
            {
                --last;
            }
        }
        else if (std::distance(first, last) <= 0)
        {
            if (*last > *first)
            {
                std::swap(*first, *last);
                std::swap(first, last);
                --last;
            }
            else
            {
                ++last;
            }
        }
    }
    return last;
}

template <typename I>
I my_quick_sort_impl(I first, I last)
{
    if (first != last)
    {
        auto cur = find_its_place(first, last);
        my_quick_sort_impl(first, cur);
        my_quick_sort_impl(cur+1, last);
        return cur;
    }
    else
    {
        return first;
    }
}

/*!
 *  example implementation for the quicksort
 */
template <typename I>
void my_quick_sort(I first, I last)
{
    my_quick_sort_impl(first, last);
}




void    std_sort();


#endif // STD_SORT_H
