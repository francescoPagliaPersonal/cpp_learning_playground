/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:28:15 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/07 19:33:20 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "BureauException.hpp"
#include <fstream>
#include <unistd.h>

int		RobotomyRequestForm::_attempt = 0;

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RRF", RRF_SIGN, RRF_EXEC),
	_target(target) {} ;

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
	: AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExec()),
	_target(obj._target) {} ;

RobotomyRequestForm::~RobotomyRequestForm(void) {} ;

std::string RobotomyRequestForm::getTarget(void) const {
	return _target;
}

RobotomyRequestForm::BureauNotSignedException::BureauNotSignedException(void) 
	: BureauException("the form is not signed") {} ;

RobotomyRequestForm::BureauNotExecutedException::BureauNotExecutedException(void) 
	: BureauException("the Bureaucrat grade is too low to execute Robotomy Request") {} ;

bool 	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->getIsFormSigned()) {
		throw BureauNotSignedException();
	}

	else if (executor.getGrade() > this->getGradeToExec()) {
		throw BureauNotExecutedException();
	}
	this->_attempt++;
	if (_attempt % 2 != 0) {
		std::cout << "Bzzzzzzzzt!...\n";
		usleep(2000);
		std::cout << "Vrrr-t-t-t-t!\n" ;
		usleep(1000);
		std::cout << "Hmmmmmm!\n" ;
		usleep(500);
		std::cout << "Whirrrrrr!\n" ;
		usleep(250);
		std::cout << "Grrrrrr-ack!\n" ;
		usleep(100);
		return true;
		std::cout << _target << " has been robotomized successfully." 
				<< std::endl;
	}
	return false;
		std::cout << "Robotomy failed." << std::endl;
};
