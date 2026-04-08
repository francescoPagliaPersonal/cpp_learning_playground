
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

#define FORMMAX 4

int main()
{
	Intern	myIntern;
	
	AForm	*forms[FORMMAX] = {
		myIntern.makeForm("Shrubbery Creation", "Shrubby"),
		myIntern.makeForm("Robotomy Request", "Roboty"),
		myIntern.makeForm("Presidential Pardon", "Pardon"),
		myIntern.makeForm("Shrubbery on", "B")
	};
	Bureaucrat mybur("Francesco", 24);
	for (int i = 0; i < FORMMAX; ++i)
	{
		std::cout << forms[i] << std::endl;
		mybur.signForm(forms[i]);
		std::cout << forms[i] << std::endl;
		mybur.executeForm(forms[i]);
	}

	for (int i = 0; i < FORMMAX; ++i)
		delete forms[i];

}

/*
try {
		_isValidGrade(grade);
		_grade = grade;
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cout << "ERROR:  " << _name << " - Grade not allowed - " << e.what()
				<< "    ...defaulting to max grade" << std::endl;
		_grade = _maxgrade;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cout << "ERROR:  " << _name << " - Grade not allowed - " << e.what()
				<< "    ...defaulting to min grade" << std::endl;
		_grade = _mingrade;
	}
*/

/*
	catch (std::exception& e)
	{
		std::cout << "ERROR:  " << _name << " - Grade not updated - " 
				<< e.what() << std::endl;
	}
*/