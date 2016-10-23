#include "std_stable_partition.hpp"
#include "../utils.hpp"

void std_stable_partition()
{
    std::vector<int> v;
    INSERT_ELEMENTS(v, 0, 15);
    PRINT_ELEMENTS(v, "before gather:");
    auto myPair = gather(std::begin(v), std::end(v), std::end(v)-1, std::function<bool(const int)>([](const int i){return (i%3)==0;})); // need this temporary std::function because a lambda does not model unaryPredicate (i.e. does not have a type "argument_type")
    PRINT_ELEMENTS(v, "after gather:");
    std::vector<int> ret {myPair.first, myPair.second};
    PRINT_ELEMENTS(ret, "gathered elements:");
}
