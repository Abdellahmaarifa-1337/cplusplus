#include "Fixed.hpp"
#include <cmath>

using std::cout;


Fixed::Fixed()
{
    this->_n = 0;
};

Fixed::Fixed(const int n)
{
    _n = (n << _frac);
};

Fixed::Fixed(const float n)
{
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
};

Fixed::Fixed(const Fixed &fix)
{
   *this = fix;
   return ;
};

Fixed &Fixed::operator=(const Fixed &fix)
{
    if (this != &fix)
        this->_n = fix.getRawBits();
    return *this;
};

bool    Fixed::operator<(const Fixed &fix) const
{
    if (this->_n < fix.getRawBits())
        return (true);
    return (false);
};

bool    Fixed::operator<=(const Fixed &fix) const
{
    if (this->_n <= fix.getRawBits())
        return (true);
    return (false);
};
bool    Fixed::operator>(const Fixed &fix) const
{
    if (this->_n > fix.getRawBits())
        return (true);
    return (false);
};
bool    Fixed::operator>=(const Fixed &fix) const
{
    if (this->_n >= fix.getRawBits())
        return (true);
    return (false);
};
bool    Fixed::operator==(const Fixed &fix) const
{
   if (this->_n == fix.getRawBits())
        return (true);
    return (false);
};
bool    Fixed::operator!=(const Fixed &fix) const
{
   if (this->_n != fix.getRawBits())
        return (true);
    return (false);
};
Fixed   Fixed::operator+(const Fixed &fix) const
{
   Fixed res;
    res.setRawBits(this->_n + fix.getRawBits());
    return res;
};
Fixed   Fixed::operator-(const Fixed &fix) const
{
    Fixed res;
    res.setRawBits(this->_n - fix.getRawBits());
    return res;
};
Fixed   Fixed::operator*(const Fixed &fix) const
{
    Fixed res;
    res.setRawBits((this->_n * fix.getRawBits() >> _frac));
    return res;
};
Fixed   Fixed::operator/(const Fixed &fix) const
{
    Fixed res;
    res.setRawBits(roundf(((long long)(this->_n) << _frac) / (fix.getRawBits())));
    return res;
};
Fixed   &Fixed::operator++()
{
    this->_n += 1;
    return *this;
};
Fixed   &Fixed::operator--()
{
    this->_n -= 1;
    return *this;
};
Fixed   Fixed::operator++(int)
{
    Fixed copy(this->toFloat());
    this->_n += 1;
    return copy;
};
Fixed   Fixed::operator--(int)
{
    Fixed copy(this->toFloat());
    this->_n -= 1;
    return copy;
};

Fixed   &Fixed::min(Fixed &fix1, Fixed &fix2)
{
    if (fix1.getRawBits() < fix2.getRawBits())
        return (fix1);
    return (fix2);
};
const Fixed   &Fixed::min(Fixed const &fix1, Fixed const &fix2)
{
   if (fix1.getRawBits() < fix2.getRawBits())
        return (fix1);
    return (fix2);
};
Fixed   &Fixed::max(Fixed &fix1, Fixed &fix2)
{
   if (fix1.getRawBits() > fix2.getRawBits())
        return (fix1);
    return (fix2);
};
const Fixed    &Fixed::max(Fixed const &fix1, Fixed const &fix2)
{
   if (fix1.getRawBits() > fix2.getRawBits())
        return (fix1);
    return (fix2);
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