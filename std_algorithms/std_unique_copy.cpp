#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

#include "std_unique_copy.h"

void std_unique_copy()
{

    std::vector<int> v{1,1,1,2,3,2,2,5,6};
    std::vector<int> v2;
    std::unique_copy(std::begin(v), std::end(v), std::back_inserter(v2));
    v.erase(my_unique_copy(std::begin(v), std::end(v), std::begin(v)) , std::end(v));

    std::cout << "Printing v:";
    std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\nPrinting v2:";
    std::copy(std::begin(v2), std::end(v2), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
}


