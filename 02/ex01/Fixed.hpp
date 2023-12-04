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
    int     getRawBits( void ) const;
    void    setRawBits(int const raw);
    float   toFloat( void ) const;
    int     toInt( void ) const;

    private:
    int _n;
    static const int _frac = 8;
};

std::ostream & operator<<(std::ostream &o, const Fixed &f);