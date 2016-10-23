#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <unordered_map>

#include "std_algorithms/std_for_each.hpp"
#include "std_algorithms/std_rotate.hpp"
#include "std_algorithms/std_stable_partition.hpp"

#include "idioms/sean_parent_polymorphism.hpp"

#include "utils.hpp"

#define EXECUTE_ALL 0

int main(int argc, char *argv[])
{
    std::unordered_map<std::string, std::function<void(void)>> test_case_list;

    test_case_list.insert({"for_each_algorithm", [](){return std_for_each();}});
    test_case_list.insert({"std_rotate", [](){return std_rotate();}});
    test_case_list.insert({"std_stable_partition", [](){return std_stable_partition();}});
    test_case_list.insert({"sean_parent_polymorphism", [](){return sean_parent_polymorphism();}});


    // following for_each executes all cases
#if(EXECUTE_ALL)
    std::for_each(begin(test_case_list), end(test_case_list), [](const std::pair<std::string, std::function<void()>> &test_case_pair){
                                                                std::cout << "\nCalling test case : " << test_case_pair.first << "...";
                                                                test_case_pair.second();
                                                                std::cout << "\nFinished Test case: " << test_case_pair.first << "\n";
                                                            });
#else

    auto ret = test_case_list.find("sean_parent_polymorphism");
    if (ret != end(test_case_list))
    {
        (*ret).second();
    }

#endif
    return 0;
}
