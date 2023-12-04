#include "Fixed.hpp"
#include <cmath>

using std::cout;


Fixed::Fixed()
{
    cout << "Default constructor called\n";    
    this->_n = 0;
};

Fixed::Fixed(const int n)
{
    cout << "Int constructor called\n";
    _n = (n << _frac);
};

Fixed::Fixed(const float n)
{
    cout << "Float constructor called\n";
    _n = roundf(n * (float)(1 << _frac));
};

float   Fixed::toFloat( void ) const
{
    return ((float)((float)_n / (float)(1 << _frac)));
};

int     Fixed::toInt( void ) const
{
    return (_n >> _frac);
};


Fixed::~Fixed()
{
    cout << "Destructor called\n";
};

Fixed::Fixed(const Fixed &fix)
{
    cout << "Copy constructor called\n";
   *this = fix;
   return ;
};

Fixed &Fixed::operator=(const Fixed &fix)
{
    cout << "Copy assignment operator called\n";
    if (this != &fix)
        this->_n = fix.getRawBits();
    return *this;
};

int Fixed::getRawBits(void) const
{
    return (this->_n);
};

void Fixed::setRawBits(int const raw)
{
    this->_n = raw;
};

std::ostream & operator<<(std::ostream &o, const Fixed &f)
{
    o << f.toFloat();
    return (o);
};