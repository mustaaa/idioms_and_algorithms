#include "std_replace_copy.h"
#include "utils.hpp"
#include <vector>
#include <algorithm>
#include <iterator>

void std_replace_copy()
{
    std::vector<int> v;
    std::vector<int> v2;
    INSERT_ELEMENTS(v, 0, 5);
    PRINT_ELEMENTS(v, "before replace_copy:");
    std::replace_copy(begin(v), end(v), std::back_inserter(v2), 3, 33);
    PRINT_ELEMENTS(v, "after v replace_copy:");
    PRINT_ELEMENTS(v2, "after v2 replace_copy:");
}
