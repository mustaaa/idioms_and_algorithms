#include "std_sort.h"
#include <list>
#include <algorithm>
#include <iostream>
#include <iterator>

void std_sort()
{
    std::cout << "std_sort!!!\n";

//    std::list<int> l;
//    l.push_back(1);
//    l.push_back(6);
//    l.push_back(5);
//    l.push_back(4);
//    l.push_back(2);
//    l.push_back(3);

//    for (auto &e:l)
//    {
//        std::cout << e << "\n";
//    }

//    l.sort();
//    std::cout << "\n";

//    for (auto &e:l)
//    {
//        std::cout << e << "\n";
//    }


    std::vector<int> v{3,7,-2,2,2,2,2,6,5,1,4,4,8};

    my_quick_sort(std::begin(v), std::end(v));

    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
}

