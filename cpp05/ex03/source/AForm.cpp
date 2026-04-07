/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:51:55 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/07 21:51:58 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
	
AForm::AForm(std::string name, int signingGrade, int executingGrade)
	: _name(name),
	_gradeToSign(isValidGrade(signingGrade)),
	_gradeToExec(isValidGrade(executingGrade)),
	_issigned(false) {} ;
	
AForm::AForm(const AForm& obj)
	: _name(obj._name),
	_gradeToSign(obj._gradeToSign),
	_gradeToExec(obj._gradeToExec),
	_issigned(false) {} ;

AForm::~AForm(void) {};

AForm::GradeTooHighException::GradeTooHighException(void) 
	: BureauException("Form value exceed max grade") {} ;

AForm::GradeTooLowException::GradeTooLowException(void) 
	: BureauException("Form value below min grade") {} ;
	
AForm::FormSignedException::FormSignedException(void) 
	: BureauException("Form already signed cannot be signed again") {} ;

AForm::GradeTooHighException::GradeTooHighException(int value) 
	: BureauException("Form value exceed max grade", value) {} ;
	
AForm::GradeTooLowException::GradeTooLowException(int value) 
	: BureauException("Form value below min grade", value) {} ;

std::string AForm::getName() const {
	return _name;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExec() const {
	return _gradeToExec;
}

bool AForm::getIsFormSigned() const {
	return _issigned;
}

bool AForm::beSigned(const Bureaucrat& obj) {
	if (obj.getGrade() > _gradeToSign)
		throw GradeTooLowException(obj.getGrade());
	else if (_issigned) {
		throw FormSignedException();
	}
	_issigned = true;
	return true;
}


int	AForm::isValidGrade(int value) const {
	if (value < HIGHEST_GRADE)
		throw GradeTooHighException(value);
	else if (value > LOWEST_GRADE)
		throw GradeTooLowException(value);
	return value;
}


std::ostream&		operator<<(std::ostream& ostream, AForm const &obj) {
	std::string status;
	obj.getIsFormSigned() == true ? status.assign("true") : status.assign("false");
	ostream << "FORM REPORT: " << obj.getName() << " Status: " << status
			<< " requires grade: " << obj.getGradeToSign() << " to be signed,"
			<< " requires grade: " << obj.getGradeToExec() << " to be executed.";
	return ostream;
};

std::ostream& operator<<(std::ostream& ostream, const AForm* obj) {
    if (!obj)
        return ostream << "NULL";
	else {
		std::string status;
		obj->getIsFormSigned() == true ? status.assign("true") : status.assign("false");
		ostream << "FORM REPORT: " << obj->getName() << " Status: " << status
				<< " requires grade: " << obj->getGradeToSign() << " to be signed,"
				<< " requires grade: " << obj->getGradeToExec() << " to be executed.";
		
		return ostream;
	}
    // return ostream << *obj; 
}