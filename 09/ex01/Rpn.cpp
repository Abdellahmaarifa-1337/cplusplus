#include "Rpn.hpp"
#include <exception>

Rpn::Rpn()
{
	
};

Rpn::Rpn(Rpn &rpn){
	this->operands = rpn.operands;
}

Rpn &Rpn::operator=(Rpn &rpn){
	this->operands = rpn.operands;
	return *this;
};

Rpn::~Rpn(){};

void Rpn::preformOperation(char c) {

	if (operands.size() < 2)
		throw std::exception();
	double op1 = operands.top();
	operands.pop();
	double op2 = operands.top();
	operands.pop();

	if (c == '+')
		operands.push(op2 + op1);
	else if (c == '-')
		operands.push(op2 - op1);
	else if (c == '*')
		operands.push(op2 * op1);
	else if (c == '/')
	{
		if (!op1) throw std::exception();
		operands.push(op2 / op1);
	}	
};

void Rpn::pushOperand(int n) {
	operands.push(n);
};

double  Rpn::getResault(){
	if (operands.size() == 1)
		return operands.top();
	else
		throw std::exception();
};

