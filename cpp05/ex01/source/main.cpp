#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "GradeException.hpp"
#include <exception>
#include <iostream>
#include <iterator>

int main()
{
	std::cout << "\n\n-------TESTING UNIQUE FORMS" 
			<<" WITH OUT OF BOUND GRADES--------\n" << std::endl;
	try {
		Form myForms("H21", 10, 1);
		std::cout << myForms << std::endl; 
	}
	catch (GradeException& e)
	{
		std::cout << "FORM NOT CREATED :  " << e.what() 
				<< " (" << e.getValue() << ")" << std::endl;
	}
	try {
		Form myForms("H22", 10, 160);
		std::cout << myForms << std::endl; 
	}
	catch (GradeException& e)
	{
		std::cout << "FORM NOT CREATED :  " << e.what() 
				<< " (" << e.getValue() << ")" << std::endl;
	}
	try {
		Form myForms("H23", 0, 150);
		std::cout << myForms << std::endl; 
	}
	catch (GradeException& e)
	{
		std::cout << "FORM NOT CREATED :  " << e.what() 
				<< " (" << e.getValue() << ")" << std::endl;
	}

	std::cout << "\n\n-------TESTING 3 FORMS IN A ROW" 
			<<" WITH OUT OF BOUND GRADES--------\n" << std::endl;
	try {
		Form myForms1("H21", 10, 1);
		Form myForms2("H22", 10, 160);
		Form myForms3("H23", 0, 150);
		std::cout << myForms1 << "\n"
				<< myForms2 << "\n"
				<< myForms3 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "FORM NOT CREATED :  " << e.what() << std::endl;
	}

	std::cout << "\n\n-------TESTING RELATIONS " 
			<<" WITH  BUREAUCRATS--------\n" << std::endl;
	Bureaucrat	bur[5] = {
		Bureaucrat("Peones", 150),
		Bureaucrat("Middle", 100),
		Bureaucrat("Senior", 30),
		Bureaucrat("TopTop", 1),
		Bureaucrat("Peone2", 148),
	} ;

	Form Form11("Form11", 31, 130);
	int i = 0;
	while (i < 5)
	{
		std::cout << "ATTEMPT: " << i << " "
			<< "Bureaucrat " << bur[i].getName() 
			<< " tries to sign the form" 
			<< std::endl; 
		try {
			if (Form11.beSigned(bur[i]))
				std::cout << bur[i].getName() << " signed "
						<< Form11.getName() << "\n" << std::endl;
			else
			 	std::cout << bur[i].getName() 
						<< " tried to sign an already signed Form" 
						<< "\n" << std::endl; 
	
		}
		catch (std::exception& e) {
			std::cout << "SIGNATURE ERROR: " << bur[i].getName() << e.what() 
					<< "\n" << std::endl;
		}
		i++;
	}
	std::cout << Form11 << std::endl;
}
