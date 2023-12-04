#include <iostream>

class Fixed
{
    public:
    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    ~Fixed();
    Fixed(const Fixed &fix);
    Fixed   &operator=(const Fixed &fix);
    bool    operator<(const Fixed &fix) const;
    bool    operator<=(const Fixed &fix) const;
    bool    operator>(const Fixed &fix) const;
    bool    operator>=(const Fixed &fix) const;
    bool    operator==(const Fixed &fix) const;
    bool    operator!=(const Fixed &fix) const;
    Fixed   operator+(const Fixed &fix) const;
    Fixed   operator-(const Fixed &fix) const;
    Fixed   operator*(const Fixed &fix) const;
    Fixed   operator/(const Fixed &fix) const;
    Fixed   &operator++();
    Fixed   &operator--();
    Fixed   operator++(int);
    Fixed   operator--(int);
    static Fixed   &min(Fixed &fix1, Fixed &fix2);
    static const Fixed   &min(Fixed const &fix1, Fixed const &fix2);
    static Fixed   &max(Fixed &fix1, Fixed &fix2);
    static const Fixed   &max(Fixed const &fix1, Fixed const &fix2);
    int     getRawBits( void ) const;
    void    setRawBits(int const raw);
    float   toFloat( void ) const;
    int     toInt( void ) const;

    private:
    int _n;
    static const int _frac = 8;
};

std::ostream & operator<<(std::ostream &o, const Fixed &f);