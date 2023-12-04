#include "ShrubberyCreationForm.hpp"
#include <fstream>  

#define TREE "\
                                                         .\n\
                                              .         ;\n\
                 .              .              ;%     ;;\n\
                   ,           ,                :;%  %;\n\
                    :         ;                   :;%;'     .,\n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n\
               ;%;      %;        ;%;        % ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%%;.%;'\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'\n\
                    `:%;.  :;bd%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'\n\
                        `@%.  `;@%.      ;@@%;\n\
                          `@%%. `@%%    ;@@%;\n\
                            ;@%. :@%%  %@@%;\n\
                              %@bd%%%bd%%:;\n\
                                #@%%%%%:;;\n\
                                %@@%%%::;\n\
                                %@@@%(o);  . '\n\
                                %@@@o%;:(.,'\n\
                            `.. %@@@o%::;\n\
                               `)@@@o%::;\n\
                                %@@(o)::;\n\
                               .%@@@@%::;\n\
                               ;%@@@@%::;.\n\
                              ;%@@@@%%:;;;.\n\
                          ...;%@@@@@%%:;;;;,..\n\
"

const char * ShrubberyCreationForm::FileError::what() const throw()
{
	return "Error: Can't open the file !\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
	std::cout << "ShrubberyCreationForm Default constractor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &sh)
: Form(sh)
{
	this->_target = sh._target;
	std::cout << "ShrubberyCreationForm copy constractor called\n";

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &sh)
{
	this->_target = sh._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destractor called\n";

}

std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::setTarget(std::string target)
{
	_target = target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	ShrubberyCreationForm::Form::execute(executor);
	if (Form::getIsSigned() && executor.getGrade() <= Form::getToExecute())
	{
		std::ofstream out(_target + "_shrubbery");
		if (!out.is_open())
		{
			throw ShrubberyCreationForm::FileError();
		}
		out << TREE;
		out.close();
	}
}

