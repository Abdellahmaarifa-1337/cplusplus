#include "Bureaucrat.hpp"


const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: The grade is too High";
};

const char *  Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: The grade is too low";
};

Bureaucrat::Bureaucrat() : _name("Default")
{
	_grade = 1;
	std::cout << WHITE << "Bureaucrat Default constractor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << WHITE << "Bureaucrat Parameterized constractor called\n";
}

Bureaucrat::Bureaucrat(Bureaucrat &b) : _name(b.getName())
{
	this->_grade = b._grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &b)
{
	this->_grade = b._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << WHITE << "Bureaucrat Destractor called\n";
}

const std::string Bureaucrat::getName()
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}



void Bureaucrat::setGrade(int grade)
{
	_grade = grade;
}

void Bureaucrat::increment()
{
	if (_grade > 1)
		_grade --;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement()
{
	if (_grade < 150)
		_grade++;
	else 
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form &f)
{
	if (f.getIsSigned())
	{
		std::cout << GREEN << "\n*********************************\n";
		std::cout <<  "\t" << _name << " signed " << f.getName() << "\n";
		std::cout << "*********************************\n\n" << WHITE;
	}
	else
	{
		std::cout << RED << "\n***************************************************************************************************\n";
		std::cout << "\t" << _name << " couldn't sign " << f.getName() << " because bureaucrat’s grade is low then the required one!\n";
		std::cout << "***************************************************************************************************\n\n" << WHITE;
	}
}

void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << GREEN << _name << " executed " << form.getName() << "\n" << WHITE;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
};


std::ostream &operator<<(std::ostream &o, Bureaucrat &b)
{
	o << GREEN << "\t" << b.getName() << ", bureaucrat grade " << b.getGrade() << WHITE <<"\n";
	return o;
}