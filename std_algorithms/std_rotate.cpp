#include <vector>
#include <algorithm>
#include "std_rotate.hpp"
#include "../utils.hpp"

void std_rotate()
{
    std::vector<int> v;
    INSERT_ELEMENTS(v, 0, 20);

    PRINT_ELEMENTS(v, "v before rotate");
    std::rotate(begin(v) + 5, begin(v) + 10, end(v));
    PRINT_ELEMENTS(v, "v after rotate");

    v.clear();
    INSERT_ELEMENTS(v, 0, 20);
    PRINT_ELEMENTS(v, "before slide:");
    auto pair = slide(v.begin(), v.end() - 3, v.end());
    PRINT_ELEMENTS(v, "after slide:");


    v.clear();
    INSERT_ELEMENTS(v, 0, 20);
    PRINT_ELEMENTS(v, "before slide:");
    pair = slide(v.begin()+5, v.begin()+10, v.begin()+5);
    PRINT_ELEMENTS(v, "after slide:");

    v.clear();
    INSERT_ELEMENTS(v, 0, 20);
    PRINT_ELEMENTS(v, "before slide:");
    pair = slide(v.begin()+5, v.begin()+10, v.end());
    PRINT_ELEMENTS(v, "after slide:");
}
