/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:06:55 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/08 13:34:09 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
#include "Form.hpp"
#include "GradeException.hpp"
#include <exception>

Bureaucrat::~Bureaucrat() {};

Bureaucrat::Bureaucrat() 
	: _name("Jhon Doe"), 
	_grade(_mingrade) {} ;
	
Bureaucrat::Bureaucrat(std::string name) 
	: _name(name), 
	_grade(_mingrade) {} ;

Bureaucrat::Bureaucrat(std::string name, int grade)
	: _name(name),
	_grade(_isValidGrade(grade)) {} ;

Bureaucrat::Bureaucrat(const Bureaucrat& obj) 
	: _name(obj._name), 
	_grade(obj._grade) {};
	
Bureaucrat::GradeTooHighException::GradeTooHighException(void) 
	: GradeException("Bureaucrat grade exceed max grade") {} ;

Bureaucrat::GradeTooLowException::GradeTooLowException(void) 
	: GradeException("Bureaucrat grade below min grade") {} ;

Bureaucrat::GradeTooHighException::GradeTooHighException(int value) 
	: GradeException("Bureaucrat grade exceed max grade", value) {} ;
	
Bureaucrat::GradeTooLowException::GradeTooLowException(int value) 
	: GradeException("Bureaucrat grade below min grade", value) {} ;
	
int	Bureaucrat::_isValidGrade(int grade) const {
	if (grade > _mingrade)
		throw GradeTooLowException(grade);
	else if (grade < _maxgrade)
		throw GradeTooHighException(grade);
	return (grade);
};

std::string	Bureaucrat::getName() const {
	return (_name);
}

int	Bureaucrat::getGrade() const {
	return (_grade);
}

bool Bureaucrat::increment(const unsigned int levels) {
	if (_isValidGrade(this->_grade - levels))
		_grade -= levels;
	return (true);
}

bool Bureaucrat::decrement(const unsigned int levels) {
	if (_isValidGrade(_grade + levels))
		_grade += levels;
	return (true);
}

std::ostream&	operator<<(std::ostream& ostream, Bureaucrat const & obj)
{
	ostream << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return ostream;
}

std::ostream&	operator<<(std::ostream& ostream, Bureaucrat const * obj)
{
	if (!obj) {
		ostream << "ERROR: Bureaucrat Pointer has NULL value and"
				<< " cannot be retrieved.";
		return ostream;
	}
	return ostream << *obj;
}

bool Bureaucrat::signForm(Form& obj) {
	try {
		if (obj.beSigned(*this))
			std::cout << this->_name << " signed " << obj.getName() << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << this->_name << " couldn’t sign " << obj.getName() 
				<< " because his grade was too low."<< std::endl;
		return false;	
	}
	catch (Form::FormSignedException& e) {
		std::cout << this->_name << " couldn’t sign " << obj.getName() 
				<< " because it was already signed."<< std::endl;
		return false;	
	}
	return true;
}
