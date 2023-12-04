#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <iterator>
#include <algorithm>


template <class T>
int easyfind(T c, int x)
{
    if (std::find(c.begin(), c.end(), x) != c.end())
        return *(std::find(c.begin(), c.end(), x));
    else
        throw std::exception();
};




#endif
