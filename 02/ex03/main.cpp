#include <iostream>
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);
int main( void ) {

    Point a(1, 1);
    Point b(3, 4);
    Point c(4, 1);

    Point p(5, 3); 	// outside
	Point i(3, 2);	// inside
	Point o(3, 4); 	// in the edge

    std::cout << bsp(a, b, c, p) << "\n";
	std::cout << bsp(a, b, c, i) << "\n";
	std::cout << bsp(a, b, c, o) << "\n";
    return 0;
}
