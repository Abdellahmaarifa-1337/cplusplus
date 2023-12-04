#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
	std::string _target;
	public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm &sh);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(RobotomyRequestForm &sh);
	void execute(Bureaucrat const & executor) const;
	std::string getTarget() const;
	void setTarget(std::string tg);
};

#endif