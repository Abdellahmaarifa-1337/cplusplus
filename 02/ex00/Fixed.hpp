#include <iostream>

class Fixed
{
    public:
    Fixed();
    ~Fixed();
    Fixed(Fixed &fix);
    Fixed &operator=(Fixed &fix);
    int getRawBits( void ) const;
    void setRawBits(int const raw);

    private:
    int _n;
    static const int _frac = 8;
};