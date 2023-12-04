#include "RobotomyRequestForm.hpp"
#include <fstream>  
#include <cstdlib>
#include <ctime>


RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	std::cout << "RobotomyRequestForm Default constractor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &sh)
: Form(sh)
{
	this->_target = sh._target;
	std::cout << "RobotomyRequestForm copy constractor called\n";

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &sh)
{
	this->_target = sh._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destractor called\n";

}

std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

void RobotomyRequestForm::setTarget(std::string target)
{
	_target = target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	RobotomyRequestForm::Form::execute(executor);
	if (Form::getIsSigned() && executor.getGrade() <= Form::getToExecute())
	{
		std::cout << "Zzzzz drilling noises Zzzzz\n";
		srand(time(0));
		bool check = rand() % 2;
		if (check)
		{
			std::cout << check << "\n";
			std::cout << _target << "has been robotomized successfully\n";
		}
		else
			std::cout << "robotomy failed.\n";
	}
}

