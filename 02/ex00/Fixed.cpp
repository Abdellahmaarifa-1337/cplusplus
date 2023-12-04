#include "Fixed.hpp"

using std::cout;


Fixed::Fixed()
{
    cout << "Default constructor called\n";    
    this->_n = 0;
};

Fixed::~Fixed()
{
    cout << "Destructor called\n";
};

Fixed::Fixed(Fixed &fix)
{
    cout << "Copy constructor called\n";
   *this = fix;
   return ;
};

Fixed &Fixed::operator=(Fixed &fix)
{
    cout << "Copy assignment operator called\n";
    this->_n = fix.getRawBits();
    return *this;
};

int Fixed::getRawBits(void) const
{
    cout << "getRawBits member function called\n";
    return (this->_n);
};

void Fixed::setRawBits(int const raw)
{
    cout << "setRawBits member function called\n";
    this->_n = raw;
};

