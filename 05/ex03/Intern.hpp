#ifndef INTERN_HPP	
#define INTERN_HPP

#include "Form.hpp"
#include <iostream>

class Intern
{
	public:
	Intern();
	Intern(Intern &intern);
	~Intern();
	Intern &operator=(Intern &intern);
	Form *makeForm(std::string form_name, std::string form_target);
};

class NotFound : public std::exception
{
	public:
	const char * what() const throw();
};

#endif