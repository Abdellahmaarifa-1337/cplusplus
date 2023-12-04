#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLACK "\033[1;30m"
#define BLUE "\033[1;34m"
#define WHITE "\033[1;37m"

class Form;
class Bureaucrat {
	private:
	const std::string _name;
	int _grade;
	public:
	Bureaucrat();
	Bureaucrat(Bureaucrat &b);
	Bureaucrat(std::string name, int grade);
	Bureaucrat &operator=(Bureaucrat &b);
	~Bureaucrat();
	const std::string getName();
	int getGrade() const;
	void setGrade(int grade);
	void increment();
	void decrement();
	void signForm(Form &f);
	void executeForm(Form const & form);
	class GradeTooHighException;
	class GradeTooLowException;

};

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
	const char * what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
	const char * what() const throw();
};

std::ostream &operator<<(std::ostream &o, Bureaucrat &b);


#endif