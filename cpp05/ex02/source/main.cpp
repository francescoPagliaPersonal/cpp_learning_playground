#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	ShrubberyCreationForm myForm("Rabbit");
	Bureaucrat myWorker("stamper", 130);
	std::cout << myForm << std::endl;
	myWorker.signForm(myForm);
	std::cout << myForm << std::endl;

	myForm.execute(myWorker);
	return 0;
}