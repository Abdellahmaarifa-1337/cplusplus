#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

template<class T>
void iter(T *arr, unsigned int size, void(*fn)(T))
{
    for(unsigned int i = 0; i < size; i++)
    {
        fn(arr[i]);
    }
}

template<class T>
void fn(T name)
{
    std::cout << "item: "<< name << "\n";
};

#endif