#ifndef STD_UNIQUE_COPY_H
#define STD_UNIQUE_COPY_H


template<typename I>
I my_unique_copy(I First, I Last, I Result)
{
    if (First == Last) {
        return Last;
    }
    *Result = *First; // init the first element
    while(++First != Last) { //pre inc first and check against the end
        if (*First != *Result) { //now First is at the next element to be chekced and the Result is at the last different element, compare them
            *++Result = *First; // if they are different assign next element to be checked (i.e. First) to the last different element (i.e. Result) and increment result
            //*++Result = std::move(*First); is this also safe?, Implementation of cpp check before doing this has another check that i dont understand. See below.
        }
    }
    return ++Result; // we should go one further from the last valid element in the result.
}

// there is this implementation example in the cpp reference site
// I do not understand the check "... && ++result != first)"
// why shoudl ++result be different than first?
template<class ForwardIt>
ForwardIt cppreference_unique(ForwardIt first, ForwardIt last)
{
    if (first == last)
        return last;

    ForwardIt result = first;
    while (++first != last) {
        if (!(*result == *first) && ++result != first) {
            *result = std::move(*first);
        }
    }
    return ++result;
}




void std_unique_copy();


#endif // STD_UNIQUE_COPY_H
