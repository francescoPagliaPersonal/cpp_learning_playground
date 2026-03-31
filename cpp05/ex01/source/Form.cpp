/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:51:55 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/31 17:24:51 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) 
	:_name("Standard Form"), 
	_gradeToSign(1),
	_gradeToExec(5), 
	_issigned(false) {} ;
	
Form::Form(std::string name, int signingGrade, int executingGrade)
	: _name(name),
	_gradeToSign(signingGrade),
	_gradeToExec(executingGrade),
	_issigned(false) {} ;
	
Form::Form(const Form& obj)
	: _name(obj._name),
	_gradeToSign(obj._gradeToSign),
	_gradeToExec(obj._gradeToExec),
	_issigned(false) {} ;

Form::~Form(void) {};

Form::GradeTooHighException::GradeTooHighException(void) 
	: GradeException("Form value exceed max grade") {} ;

Form::GradeTooHighException::~GradeTooHighException() {} ;

Form::GradeTooLowException::GradeTooLowException(void) 
	: GradeException("Form value below min grade") {} ;

Form::GradeTooLowException::~GradeTooLowException() {} ;

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
		throw GradeTooLowException();
	else
		_issigned = true;
	return true;
}

std::ostream&		operator<<(std::ostream& ostream, Form const &obj) {
	std::string status;
	obj.getIsFormSigned() == true ? status.assign("true") : status.assign("false");
	ostream << "Form: " << obj.getName() << " Status: " << status
			<< " requires grade: " << obj.getGradeToSign() << " to be signed,"
			<< " requires grade: " << obj.getGradeToExec() << " to be executed,"
			<< std::endl;
	return ostream;
}
;
