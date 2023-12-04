#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
	std::string _target;
	public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm &sh);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(ShrubberyCreationForm &sh);
	void execute(Bureaucrat const & executor) const;
	std::string getTarget() const;
	void setTarget(std::string tg);
	Form *createShrubberyCreationForm(std::string form_target);
	class FileError;
};

class ShrubberyCreationForm::FileError : public std::exception
{
	public:
	const char * what() const throw();
};
#endif