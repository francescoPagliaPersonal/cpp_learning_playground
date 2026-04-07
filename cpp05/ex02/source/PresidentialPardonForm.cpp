/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:28:03 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/07 19:42:38 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureauException.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PPF", PPF_SIGN, PPF_EXEC),
	_target(target) {} ;

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
	: AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExec()),
	_target(obj._target) {} ;

PresidentialPardonForm::~PresidentialPardonForm(void) {} ;

std::string PresidentialPardonForm::getTarget(void) const {
	return _target;
}

PresidentialPardonForm::BureauNotSignedException::BureauNotSignedException(void) 
	: BureauException("the form is not signed") {} ;

PresidentialPardonForm::BureauNotExecutedException::BureauNotExecutedException(void) 
	: BureauException("the Bureaucrat grade is too low to execute Presidential Pardon") {} ;

bool 	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->getIsFormSigned()) {
		throw BureauNotSignedException();
	}

	else if (executor.getGrade() > this->getGradeToExec()) {
		throw BureauNotExecutedException();
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." 
			<< std::endl;
	return true;
};
