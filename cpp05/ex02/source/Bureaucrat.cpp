/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:06:55 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/03 16:10:39 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat() {};
Bureaucrat::Bureaucrat() : _name("Jhon Doe"), _grade(_mingrade) {} ;
Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(_mingrade) {} ;
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	try {
		_check_grade(grade);
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
} ;

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade) {};

Bureaucrat::GradeTooHighException::GradeTooHighException(void) 
	: GradeException("Bureaucrat grade exceed max grade") {} ;

Bureaucrat::GradeTooLowException::GradeTooLowException(void) 
	: GradeException("Bureaucrat grade below min grade") {} ;

Bureaucrat::GradeTooHighException::GradeTooHighException(int value) 
	: GradeException("Bureaucrat grade exceed max grade", value) {} ;
	
Bureaucrat::GradeTooLowException::GradeTooLowException(int value) 
	: GradeException("Bureaucrat grade below min grade", value) {} ;
	
bool	Bureaucrat::_check_grade(int grade) const {
	if (grade > _mingrade)
		throw GradeTooLowException(grade);
	else if (grade < _maxgrade)
		throw GradeTooHighException(grade);
	return (true);
};

std::string	Bureaucrat::getName() const {
	return (_name);
}

int	Bureaucrat::getGrade() const {
	return (_grade);
}

bool Bureaucrat::increment(const unsigned int levels) {
	try {
		_check_grade(this->_grade - levels);
		_grade -= levels;
	}
	catch (std::exception& e)
	{
		std::cout << "ERROR:  " << _name << " - Grade not updated - " 
				<< e.what() << std::endl;
	}
	return (true);
}

bool Bureaucrat::decrement(const unsigned int levels) {
	try {
		_check_grade(_grade + levels);
		_grade += levels;

	}
	catch (std::exception& e)
	{
		std::cout << "ERROR:  " << _name << " - Grade not updated - " 
				<< e.what() << std::endl;
	}
	return (true);
}

std::ostream&	operator<<(std::ostream& ostream, Bureaucrat const &obj)
{
	ostream << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return ostream;
}


bool Bureaucrat::signForm(AForm& obj) {
	std:: cout << this->_name ;
	try {
		if (obj.beSigned(*this))
			std:: cout << " signed " << obj.getName() << std::endl;
		else {
			std:: cout << " couldn’t sign " << obj.getName() 
					<< " because it was already signed."<< std::endl;
			return false;	
		}
	}
	catch (AForm::GradeTooLowException& e)
	{
		std:: cout << " couldn’t sign " << obj.getName() 
				<< " because his grade was too low."<< std::endl;
		return false;	
	}
	return true;
}
