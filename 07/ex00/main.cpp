#include <iostream>
#include "template.hpp"

// class Test {
// 	private:
// 	int _num;
// 	public:
// 	Test(){_num = 0;};
// 	Test(int n){_num = n;};
// 	bool operator==(const Test &ts){return (this->_num == ts._num);};
// 	bool operator!=(const Test &ts){return (this->_num != ts._num);};
// 	bool operator>(const Test &ts){return (this->_num > ts._num);};
// 	bool operator<(const Test &ts){return (this->_num < ts._num);};
// 	bool operator>=(const Test &ts){return (this->_num >= ts._num);};
// 	bool operator<=(const Test &ts){return (this->_num <= ts._num);};
// 	int get_num() const {return _num;};
// };
// std::ostream &operator<<(std::ostream &o, const Test &a){
// 	o << a.get_num();
// 	return o;
// };

int main()
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	// Test j(13);
	// Test h(9);
	// std::cout << "min: " << ::min(j, h) << "\n";
	// std::cout << "max: " << ::max(j, h) << "\n";
	return 0;
}