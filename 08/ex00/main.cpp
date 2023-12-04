#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <array>
#include <set>

int main()
{
    try 
    {
        // vector 
        std::vector<int> c;
        for(int i = 0; i < 10; i++)
        {
            c.push_back(i);
        }
        std::cout << easyfind<std::vector<int> >(c, 9) << "\n";

        // array
        std::array<int, 10> arr = {1,2,3,4,5,6,7,8,9};
        std::cout << easyfind<std::array<int, 10> >(arr, 4) << "\n";

        // set
        int num[] = {1,2,3,4,5,6,7,8,9};
        std::set<int> s(num, num + sizeof(num) / sizeof(num[0]));
        std::cout << easyfind< std::set<int> >(s, 5) << "\n";
        std::cout << easyfind< std::set<int> >(s, 11) << "\n";
    }
    catch(std::exception &)
    {
        std::cout << "Error\n" << "\n";
    }
    
    return 0;
}