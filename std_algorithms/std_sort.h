#ifndef STD_SORT_H
#define STD_SORT_H

#include <utility>
#include <iterator>

/*!
 *  moves the first element in the range [first, last) to its place
 *  as if the range were sorted.
 */
template <typename I, //I models bidirectional iterator
          typename P> //P models binary predicate
I place_first_element_to_its_place(I first, I last, P pred)
{
    if (first == last)
        return last;
    else
        --last;
    while (first != last)
    {
        if (std::distance(first, last) > 0)
        {
            if (pred(*last, *first))
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
            if (!pred(*last, *first))
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

template <typename I, //I models bidirectional iterator
          typename P> //P models binary predicate
I my_quick_sort_impl(I first, I last, P pred)
{
    if (first != last)
    {
        auto cur = place_first_element_to_its_place(first, last, pred);
        my_quick_sort_impl(first, cur, pred);
        my_quick_sort_impl(cur+1, last, pred);
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
template <typename I> //I models bidirectional iterator
void my_quick_sort(I first, I last)
{
    my_quick_sort_impl(first, last, std::less<typename I::value_type>());
}

template <typename I, //I models bidirectional iterator
          typename P> //P models binary predicate
void my_quick_sort(I first, I last, P pred)
{
    my_quick_sort_impl(first, last, pred);
}




void    std_sort();


#endif // STD_SORT_H
