#include "Span.hpp"
#include <cmath>
#include <numeric>
#include <algorithm>

Span::Span()
{
    max = 0;
};
Span::Span(unsigned int n)
{
    max = n;
};
Span::~Span()
{
 
};
Span::Span(Span &s)
{
    *this = s;
};
Span &Span::operator=(Span &s)
{
    this->num = s.num;
    this->max = s.max;
    return *this;
};
void Span::addNumber(int number)
{
    if (num.size() < max)
        num.push_back(number);
    else
        throw std::exception();
};


void Span::fill(unsigned int number)
{
    if (number >= (this->max - num.size()))
        throw std::exception();
    for(unsigned int i = 0; i < number; i++)
    {
        num.push_back(rand());
    }
};

unsigned int Span::shortestSpan()
{
    if (num.size() < 2)
        throw std::exception();
    std::vector<int> copy = num;
    std::vector<int> result(num.size());
    std::sort(copy.begin(), copy.end());
    std::adjacent_difference(copy.begin(), copy.end(), result.begin());
    std::vector<int>::iterator itr = result.begin();
    for(; itr != result.end(); itr++)
        if (*itr < 0)
            *itr = *itr * -1;
    std::vector<int>::iterator res = std::min_element(result.begin() + 1, result.end());
    return *res;

};
unsigned int Span::longestSpan()
{
    if (num.size() < 2)
        throw std::exception();
    std::vector<int> copy = num;
    std::sort(copy.begin(), copy.end());
    int res = copy[copy.size() - 1] - copy[0];
    return res >= 0 ? res : -res;
};