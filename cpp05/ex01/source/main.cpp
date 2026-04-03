#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "GradeException.hpp"
#include <exception>
#include <iostream>

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

	for (int i = 0; i < 5 ; ++i) {
		std::cout << bur[i] << std::endl;
	}

	std::cout << "\n\n-------TESTING Form::beSigned() " 
			<<"--------\n" << std::endl;

	Form	Form1A("Form1A", 31, 130);
	
	for (int i = 0; i < 5 ; ++i) {
		std::cout << "ATTEMPT: " << i << " "
			<< "Bureaucrat " << bur[i].getName() 
			<< " tries to sign the form" 
			<< std::endl; 
		try {
			if (Form1A.beSigned(bur[i]))
				std::cout << bur[i].getName() << " signed "
						<< Form1A.getName() << "\n" << std::endl;
			else
			 	std::cout << bur[i].getName() 
						<< " tried to sign an already signed Form" 
						<< "\n" << std::endl; 
	
		}
		catch (std::exception& e) {
			std::cout << "SIGNATURE ERROR: " << bur[i].getName() << e.what() 
					<< "\n" << std::endl;
		}
	}

	std::cout << "\n\n" << Form1A << std::endl;

	std::cout << "\n\n-------TESTING Bureaucrat::signForm() " 
			<<"--------\n" << std::endl;

	Form	Form2B("Form2B", 101, 100);
	
	for (int i = 0; i < 5 ; ++i) {
		bur[i].signForm(Form2B);
	}
	
	std::cout << "\n\n" << Form2B << std::endl;
}
