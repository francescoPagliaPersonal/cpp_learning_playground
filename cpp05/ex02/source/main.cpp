#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	std::cout << "\n\n----------SETUP BUREAUCRATS----------\n" << std::endl;
	Bureaucrat	bur[5] = {
		Bureaucrat("Peones", 150),
		Bureaucrat("Middle", 100),
		Bureaucrat("Senior", 30),
		Bureaucrat("TopTop", 10),
		Bureaucrat("TipTo2", 1),
	} ;

	for (int i = 0; i < 5 ; ++i) {
		std::cout << bur[i] << std::endl;
	}

	std::cout << "\n\n----------SETUP FORMS----------\n" << std::endl;
	// TODO: to modify with the new additional classes
	AForm *forms[3] = {
		new ShrubberyCreationForm("Honey"),
		new ShrubberyCreationForm("Biney"),
		new ShrubberyCreationForm("Piney"),
	};

	for (int i = 0; i < 3 ; ++i) {
		std::cout << *forms[i] << std::endl;
	}

	std::cout << "\n\n----------SIGN FORMS----------\n" << std::endl;
	for (int i = 0; i < 5 ; ++i) {
		for (int j = 0; j < 3; ++j)
			if (bur[i].signForm(*forms[j]))
				break;
	}

	std::cout << "\n\n----------EXECUTE FORMS----------\n" << std::endl;
	int j = 0;
	for (int i = 0; i < 5 ; ++i) {
		if (bur[i].executeForm(*forms[j]) && j < 2)
			j++;
	}

	for (int i = 0; i < 3 ; ++i) {
		delete forms[i];
	}
	return 0;
}