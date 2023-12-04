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
	virtual ~Form();
	Form(Form &form);

	Form 				&operator=(Form &form);
	std::string 		getName() const;
	bool				getIsSigned() const;
	int					getToSign() const;
	int					getToExecute() const ;
	void				beSigned(Bureaucrat &b);
	virtual void		execute(Bureaucrat const & executor) const = 0;
	class				GradeTooHighException;
	class				GradeTooLowException;
	class				FormUnsigned;
	class				LowGrade;
};

class Form::FormUnsigned : public std::exception
{
	public:
	const char * what() const throw();
};

class Form::LowGrade : public std::exception
{
	public:
	const char * what() const throw();
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