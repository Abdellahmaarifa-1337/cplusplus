#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
	std::cout << "PresidentialPardonForm Default constractor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &sh)
: Form(sh)
{
	this->_target = sh._target;
	std::cout << "PresidentialPardonForm copy constractor called\n";

}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &sh)
{
	this->_target = sh._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destractor called\n";

}

std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}

void PresidentialPardonForm::setTarget(std::string target)
{
	_target = target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	PresidentialPardonForm::Form::execute(executor);
	if (Form::getIsSigned() && executor.getGrade() <= Form::getToExecute())
	{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
	}
}

