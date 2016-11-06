#include "std_inplace_merge.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>


template <typename I>
void mergeSort (I first, I last)
{
    if (std::distance(first, last) > 1)
    {
        auto mid = first + std::distance(first, last) / 2;
        mergeSort(first, mid);
        mergeSort(mid, last);
        std::inplace_merge(first, mid, last, []( const typename I::value_type e1,
                                                 const typename I::value_type e2)
        {return e1 > e2;});
    }
}


void std_inplace_merge()
{
    std::cout << "implementation of the merge sort using std::inplace_merge\n";
    std::vector<int> v {2,3,51,3,53,6,34,5,57,73,5,7,4456,7,3,6,7,89,9,0,23};
    mergeSort(begin(v), end(v));
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}
