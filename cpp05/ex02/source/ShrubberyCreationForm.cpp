#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "GradeException.hpp"
#include <ios>
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("SCF", REGRAD_SIGN, REGRAD_EXEC),
	_target(target) {} ;

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
	: AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExec()),
	_target(obj._target) {} ;

ShrubberyCreationForm::~ShrubberyCreationForm(void) {} ;

std::string ShrubberyCreationForm::getTarget(void) const {
	return _target;
}

ShrubberyCreationForm::GradeNotSignedException::GradeNotSignedException(void) 
	: GradeException("the form is not signed") {} ;

ShrubberyCreationForm::GradeNotExecutedException::GradeNotExecutedException(void) 
	: GradeException("the Bureaucrat grade is too low to execute") {} ;
	

bool 	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getIsFormSigned()) {
		throw GradeNotSignedException();
	}

	else if (executor.getGrade() > this->getGradeToExec()) {
		throw GradeNotExecutedException();
	}

	std::string 	filename(_target + "_shrubbery");
	std::ofstream	outfs(filename.c_str());

	if (!outfs.is_open())
		throw std::ios_base::failure("Could not create the file");

	outfs << "     ccee88oo\n  C8O8O8Q8PoOb o8oo\n dOB69QO8PdUOpugoO9bD\n"
		<< "CgggbU8OU qOp qOdoUOdcb\n    6OuU  /p u gcoUodpP\n"
		<< "      \\\\\\//  /douUP\n        \\\\\\////\n         |||/\\\n"
		<< "         |||\\/\n         |||||\n   .....//||||\\....\n"
		<< "  ..................\n thanks to David Moore\n";
	outfs.close();
	return true;
};

/*
     ccee88oo
  C8O8O8Q8PoOb o8oo
 dOB69QO8PdUOpugoO9bD
CgggbU8OU qOp qOdoUOdcb
    6OuU  /p u gcoUodpP
      \\\//  /douUP
        \\\////
         |||/\
         |||\/
         |||||
   .....//||||\....
  ..................
 thanks to David Moore
*/
