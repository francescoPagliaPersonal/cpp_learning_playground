/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:51:55 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/08 13:40:07 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
	
Form::Form(std::string name, int signingGrade, int executingGrade)
	: _name(name),
	_gradeToSign(isValidGrade(signingGrade)),
	_gradeToExec(isValidGrade(executingGrade)),
	_issigned(false) {} ;
	
Form::Form(const Form& obj)
	: _name(obj._name),
	_gradeToSign(obj._gradeToSign),
	_gradeToExec(obj._gradeToExec),
	_issigned(false) {} ;

Form::~Form(void) {};

Form::GradeTooHighException::GradeTooHighException(void) 
	: GradeException("Form value exceed max grade") {} ;

Form::GradeTooLowException::GradeTooLowException(void) 
	: GradeException("Form value below min grade") {} ;

Form::FormSignedException::FormSignedException(void) 
	: GradeException("Form already signed cannot be signed again") {} ;
	
Form::GradeTooHighException::GradeTooHighException(int value) 
	: GradeException("Form value exceed max grade") {
		_value = value;
	} ;
	
Form::GradeTooLowException::GradeTooLowException(int value) 
	: GradeException("Form value below min grade") {
		_value = value;
	} ;

std::string Form::getName() const {
	return _name;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExec() const {
	return _gradeToExec;
}

bool Form::getIsFormSigned() const {
	return _issigned;
}

bool Form::beSigned(const Bureaucrat& obj) {
	if (obj.getGrade() > _gradeToSign)
		throw GradeTooLowException(obj.getGrade());
	else if (_issigned) {
		throw FormSignedException();
	}
	_issigned = true;
	return true;
}

int	Form::isValidGrade(int value) const {
	if (value < HIGHEST_GRADE)
		throw GradeTooHighException(value);
	else if (value > LOWEST_GRADE)
		throw GradeTooLowException(value);
	return value;
}


std::ostream&		operator<<(std::ostream& ostream, Form const &obj) {
	std::string status;
	obj.getIsFormSigned() == true ? status.assign("true") : status.assign("false");
	ostream << "FORM REPORT: " << obj.getName() << " Status: " << status
			<< " requires grade: " << obj.getGradeToSign() << " to be signed,"
			<< " requires grade: " << obj.getGradeToExec() << " to be executed." ;
	return ostream;
};

std::ostream& operator<<(std::ostream& ostream, const Form* obj) {
	if (!obj)
		return ostream << "FORM REPORT: Form Pointer has NULL value and"
						<< " cannot be retrieved.";
	return ostream << *obj;
}
