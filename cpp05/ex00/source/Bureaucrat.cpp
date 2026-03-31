/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:06:55 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/31 13:41:34 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
#include <exception>

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
				<< "    ...defaulting to max grade" << std::endl;
		_grade = _mingrade;
	}
} ;

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string what_msg, int grade)
	: std::invalid_argument (what_msg), _futureGrade(grade) {} ;

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string what_msg, int grade)
	: std::invalid_argument (what_msg), _futureGrade(grade) {} ;

	
bool	Bureaucrat::_check_grade(int grade) const {
	if (grade > _mingrade)
		throw Bureaucrat::GradeTooLowException("value below max grade", grade);
	else if (grade < _maxgrade)
		throw Bureaucrat::GradeTooHighException("value exceed max grade", grade);
	return (true);
};

std::string	Bureaucrat::getName() const {
	return _name;
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

int		Bureaucrat::GradeTooHighException::getWrongGrade() const{
	return _futureGrade;
}; 

int		Bureaucrat::GradeTooLowException::getWrongGrade() const{
	return _futureGrade;
}; 