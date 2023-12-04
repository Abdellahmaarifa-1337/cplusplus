#include <iostream>
#include "Span.hpp"

int main()
{
    try 
    {
        Span n(7);
        n.addNumber(1);
        n.addNumber(6);
        n.addNumber(8);
        n.addNumber(12);
        n.addNumber(16);
        n.addNumber(91);
        n.addNumber(77);
        std::cout << "min " << n.shortestSpan() << "\n";
        std::cout << "max " << n.longestSpan() << "\n\n";
        Span n2(10000);
        n2.fill(10000 - 1);
        std::cout << n2.shortestSpan() << "\n";
        std::cout << n2.longestSpan() << "\n";
        n.addNumber(8);
    }
    catch(std::exception &)
    {
        std::cout << "Error!" << std::endl;
    }
  
    return 0;
}