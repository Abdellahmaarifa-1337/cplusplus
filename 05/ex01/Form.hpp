#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form 
{
	private:
	const std::string	_name;
	bool				_is_signed;
	const int			_toSign;
	const int			_toExecute;
	public:
	Form();
	Form(std::string name, const int toSign, const int toExecute);
	~Form();
	Form(Form &form);
	Form &operator=(Form &form);
	std::string	getName() const;
	bool				getIsSigned() const;
	int			getToSign() const;
	int			getToExecute() const;
	void	beSigned(Bureaucrat &b);
	class GradeTooHighException;
	class GradeTooLowException;
};

class Form::GradeTooHighException : public std::exception
{
	public:
	const char * what() const throw();
};


class Form::GradeTooLowException : public std::exception
{
	public:
	const char * what() const throw();
};

std::ostream &operator<<(std::ostream &o, Form &f);

#endif