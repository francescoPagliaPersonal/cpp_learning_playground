
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
	Intern	test;
	AForm	*A = test.makeForm("Shrubbery Creation", "A");
	AForm	*B = test.makeForm("Shrubbery on", "B");
	Bureaucrat mybur("Francesco", 24);
	std::cout << A << B
			<< std::endl;
	mybur.signForm(*A);
	delete A;
	delete B;

}