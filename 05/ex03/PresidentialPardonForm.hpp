#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
	std::string _target;
	public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm &sh);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(PresidentialPardonForm &sh);
	void execute(Bureaucrat const & executor) const;
	std::string getTarget() const;
	void setTarget(std::string tg);

};

#endif
