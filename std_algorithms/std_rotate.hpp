#ifndef STD_ROTATE_H
#define STD_ROTATE_H
#include <algorithm>

void std_rotate();

//In Sean Parent's talk in C9 he talks about implementing slide in terms of rotate
//https://channel9.msdn.com/Events/GoingNative/2013/Cpp-Seasoning
//here is his template implementation which takes three iterators f,l,p (random access)
//f: beginning of the sequence of elements which will be slided
//l: end of the sequence of elements which will be slided
//p: position to slide the sequence to. If sliding to right it will be
//the end of the sequence, If sliding to left it will be the position of the
//first element.
//return pair is the begin and end of the slided sequence

template <typename I> // I models RandomAccessIterator
auto slide(I f, I l, I p) -> std::pair<I, I>
{
    if (p < f) return {p, std::rotate(p, f, l)};
    if (l < p) return {std::rotate(f, l, p), p};
    return {f, l};
}


#endif // STD_ROTATE_H
