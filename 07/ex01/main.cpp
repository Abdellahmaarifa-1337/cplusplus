#include <iostream>
#include "template.hpp"


// class Test
// {
//     private:
//     int _num;
//     public:
//     Test(){_num = 10;};
//     int get() const{return _num;};
// };
// std::ostream &operator<<(std::ostream &o,  Test &ts)
// {
//     o << ts.get();
//     return o;
// };

int main()
{
    std::cout << "-------------- string test -----------------" << std::endl;

    std::string arr[5] = {"abdellah", "ayoub", "ilyass", "mounia", "sara"};
    iter<std::string>(arr, 5, fn<std::string>);
    
    std::cout << "-------------- int test -----------------" << std::endl;

    int intarr[5] = {1, 2, 3, 4, 5};
    iter<int>(intarr, 5, fn<int>);

    std::cout << "-------------- double test -----------------" << std::endl;

    float floatarr[5] = {1.4, 2.2, 3.8, 4.4, 5.2};
    iter<float>(floatarr, 5, fn<float>);

    // Test testArr[8];
    // iter<Test>(testArr, 5, fn<Test>);
}