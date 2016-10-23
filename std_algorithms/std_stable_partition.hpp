#ifndef STD_STABLE_PARTITION_H
#define STD_STABLE_PARTITION_H
#include <algorithm>
#include <utility>
#include <functional>

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


#endif // STD_STABLE_PARTITION_H
