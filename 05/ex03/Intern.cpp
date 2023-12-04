#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


const char * NotFound::what() const throw()
{
	return "This form dosen't exist!";
};

Intern::Intern()
{
	std::cout << "Default constructor called\n";
};

Intern::~Intern()
{
	std::cout << "Intern deconstructor called\n";
};

Intern::Intern(Intern &intern)
{
	(void)intern;
};

Intern &Intern::operator=(Intern &intern)
{
	(void)intern;
	return *this;
};


Form	*createShrubberyCreationForm(std::string form_target)
{
	return new ShrubberyCreationForm(form_target);
}

Form	*createRobotomyRequestForm(std::string form_target)
{
	return new RobotomyRequestForm(form_target);
}

Form	*createPresidentialPardonForm(std::string form_target)
{
	return new PresidentialPardonForm(form_target);
}

Form *Intern::makeForm(std::string form_name, std::string form_target)
{
	std::string forms_name[3] = {"shrubbery creation",
	"robotomy request", "presidential pardon"};
	int i = 0;
	Form *(*fn[3])(std::string form_target) = {
		createShrubberyCreationForm,
		createRobotomyRequestForm,
		createPresidentialPardonForm
	};
	Form *fm = NULL;
	while (i < 3)
	{	
		if (form_name == forms_name[i])
			break;
		i++;
	}
	i > 2 ? throw NotFound() : fm = (fn[i])(form_target);
	return fm;
}
