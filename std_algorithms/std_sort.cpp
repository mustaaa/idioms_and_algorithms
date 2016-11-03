#include "std_sort.h"
#include <list>
#include <algorithm>
#include <iostream>

void std_sort()
{
    std::cout << "std_sort!!!\n";

    std::list<int> l;
    l.push_back(1);
    l.push_back(6);
    l.push_back(5);
    l.push_back(4);
    l.push_back(2);
    l.push_back(3);

    for (auto &e:l)
    {
        std::cout << e << "\n";
    }

    l.sort();
    std::cout << "\n";

    for (auto &e:l)
    {
        std::cout << e << "\n";
    }
}

