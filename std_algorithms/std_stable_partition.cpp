#include "std_stable_partition.hpp"
#include "../utils.hpp"
#include <iostream>


void std_stable_partition()
{
    // test for the gather function 
    std::vector<int> v;
    INSERT_ELEMENTS(v, 0, 15);
    PRINT_ELEMENTS(v, "before gather:");
    auto myPair = gather(std::begin(v), std::end(v), std::end(v)-1, std::function<bool(const int)>([](const int i){return (i%3)==0;})); // need this temporary std::function because a lambda does not model unaryPredicate (i.e. does not have a type "argument_type")
    PRINT_ELEMENTS(v, "after gather:");
    std::vector<int> ret {myPair.first, myPair.second};
    PRINT_ELEMENTS(ret, "gathered elements:");

    // test for the my_stable_partition implementation
    std::cout << "\n\nBefor my_stable_partition:\n";
    std::vector<int> v2 {1,2,5,6,43,3,4,10,343,4,63,63,4,0,7,47,52,4,2,57213,2,32,12};
    auto pred = [](const int& e) { return e>15;};
    std::copy(std::begin(v2), std::end(v2), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nafter my_stable_partition\n";
    my_stable_partition(std::begin(v2), std::end(v2), pred);
    std::copy(std::begin(v2), std::end(v2), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}



