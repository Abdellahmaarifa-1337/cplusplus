#include "Form.hpp"
#include "Bureaucrat.hpp"


const char * Form::GradeTooLowException::what() const throw()
{
	return "Error: The grade is too low\n";
}
const char * Form::GradeTooHighException::what() const throw()
{
	return "Error: The grade is too High\n";
}

const char * Form::FormUnsigned::what() const throw()
{
	return "Form creation form failed : The form is unsigned !";
}

const char * Form::LowGrade::what() const throw()
{
	return "Form creation failed :Not enugh grade to execute !";
}

Form::Form() : _name(""), _toSign(0), _toExecute(0)
{
	std::cout << "Form Default constractor called\n";
	_is_signed = false;
}

Form::Form(std::string name, const int toSign,
const int toExecute) : _name(name), _toSign(toSign), _toExecute(toExecute)
{
	std::cout << "Form Parameterized constractor called\n";
	_is_signed = false;
};


Form::Form(Form &form): _name(form.getName()), _toSign(form.getToSign()), _toExecute(form.getToExecute())
{
	this->_is_signed = form.getIsSigned();
}

Form &Form::operator=(Form &form)
{
	this->_is_signed = form.getIsSigned();
	return  *this;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _is_signed;
}

int Form::getToSign() const
{
	return _toSign;
}

int Form::getToExecute() const
{
	return _toExecute;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= _toSign)
	{
		_is_signed = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

void		Form::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw FormUnsigned();
	else if (executor.getGrade() > getToExecute())
		throw LowGrade();
	return ;
}

Form::~Form()
{
	std::cout << "Form destractor called\n";
}