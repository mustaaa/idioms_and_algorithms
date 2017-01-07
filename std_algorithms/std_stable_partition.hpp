#ifndef STD_STABLE_PARTITION_H
#define STD_STABLE_PARTITION_H
#include <algorithm>
#include <utility>
#include <functional>
#include <iterator>

void std_stable_partition();


//In Sean Parent's talk in C9 he talks about implementing a "gather function,
//https://channel9.msdn.com/Events/GoingNative/2013/Cpp-Seasoning
//here is his template gather implementation:

template <typename I, // I models BidirectionalIterator
          typename S> // S models UnaryPredicate
auto gather(I f, I l, I p, S s) -> std::pair<I, I>
{
    return {
        std::stable_partition(f, p, std::not1(s)),
        std::stable_partition(p, l, s)
    };
}

/*!
 * Implementation of the stable partition in terms of std rotate.
 */
template <typename I, //I models bidirectional iterator
          typename S> //U models UnaryPredicate
auto my_stable_partition (I first, I last, S pred) -> I //beginning of the elements which do not satisfy pred
{
    if (std::distance(first, last) > 2)
    {
        auto mid = first + (std::distance(first, last) / 2);
        auto first_end = my_stable_partition(first, mid, pred);
        auto second_end =  my_stable_partition(mid, last, pred);
        return std::rotate(first_end, mid, second_end);
    }
    if (std::distance(first, last) == 2)
    {
        auto mid = first + (std::distance(first, last) / 2);
        if ((pred(*first)) && (!pred(*mid)))
        {
            return mid;
        }
        else if ((!pred(*first)) && (pred(*mid)))
        {
            return std::rotate(first, mid, last);
        }
        else if ((!pred(*first) && !pred(*mid)))
        {
            return first;
        }
        else // both satisfy
        {
            return last;
        }

    }
    else if (std::distance(first,last) == 1) // single element
        if (!pred(*first))
            return first;
        else
            return last;
    else
        return last;
}


#endif // STD_STABLE_PARTITION_H
