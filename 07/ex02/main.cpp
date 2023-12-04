#include <iostream>
#include "Array.hpp"

// class Test
// {
//     private:
//     int _num;
//     public:
//     Test(){_num = 20;};
//     int get() const{return _num;};
// };
// std::ostream &operator<<(std::ostream &o,  Test &ts)
// {
//     o << ts.get();
//     return o;
// };


int main()
{
	try {
		std::cout << "--------------int array test---------" << std::endl;
		Array<int> intarr(8);
		// fill out the array
		for(unsigned int i = 0; i < intarr.size(); i++)
			intarr[i] = i + 1;
		// print the intarr values
		for(unsigned int i = 0; i < intarr.size(); i++)
			std::cout << "intarr[" << i << "] = " << intarr[i] << "\n";

		std::cout << "--------------copy int array test---------" << std::endl;
		// copy to another array
		Array<int> intarr_1 = intarr;
		// change the original intarr value
		for(unsigned int i = 0; i < intarr.size(); i++)
			intarr[i] = i + 5;
		// print the intarr1 values
		for(unsigned int i = 0; i < intarr_1.size(); i++)
			std::cout << "intarr_1[" << i << "] = " << intarr_1[i] << "\n";

		std::cout << "--------------string array test---------" << std::endl;
		Array<std::string> strarr(5);
		strarr[0] = "abdellah";
		strarr[1] = "ayoub";
		strarr[2] = "sara";
		strarr[3] = "ilyass";
		strarr[4] = "mounia";
		for(unsigned int i = 0; i < strarr.size(); i++)
			std::cout << "strarr[" << i << "] = " << strarr[i] << "\n";

		std::cout << "--------------double array test---------" << std::endl;
		Array<double> doublearr(3);
		doublearr[0] = 1.2;
		doublearr[1] = 2.1;
		doublearr[2] = 42.2;
		for(unsigned int i = 0; i < doublearr.size(); i++)
			std::cout << "doublearr[" << i << "] = " << doublearr[i] << "\n";

		// std::cout << "--------------Test obj array test---------" << std::endl;
		// Array<Test> testarr(8);
		// for(unsigned int i = 0; i < testarr.size(); i++)
		// 	std::cout << "testarr[" << i << "] = " << testarr[i] << "\n";
	} catch(std::exception &e)
	{
		std::cout << "bad access\n" << "\n";
	}
	return 0;
}


// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }