#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>

class Span
{
    private:
    std::vector<int>num;
    unsigned int max;
    public:
    Span();
    Span(unsigned int n);
    ~Span();
    Span(Span &s);
    Span &operator=(Span &s);
    void addNumber(int number);
    void fill(unsigned int number);
    unsigned int shortestSpan();
    unsigned int longestSpan();
};
#endif