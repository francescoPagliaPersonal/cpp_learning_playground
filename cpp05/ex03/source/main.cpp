
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

#define FORMMAX 4

int main()
{
	Intern	test;
	
	AForm	*forms[FORMMAX] = {
		test.makeForm("Shrubbery Creation", "Shrubby"),
		test.makeForm("Robotomy Request", "Roboty"),
		test.makeForm("Presidential Pardon", "Pardon"),
		test.makeForm("Shrubbery on", "B")
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