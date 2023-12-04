#include <iostream>
#include <stack> 

class Rpn {
	private:
	std::stack<double> operands;
	public:
	Rpn();
	Rpn(Rpn &rpn);
	Rpn &operator=(Rpn &rpn);
	void preformOperation(char c);
	void pushOperand(int n);
	double  getResault();
	~Rpn();
};


// 10 6 9 3 + -11 * / * 17 + 5 +