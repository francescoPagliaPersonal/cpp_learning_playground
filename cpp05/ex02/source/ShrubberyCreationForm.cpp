/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:28:11 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/07 19:28:12 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "BureauException.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("SCF", SCF_SIGN, SCF_EXEC),
	_target(target) {} ;

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
	: AForm(obj.getName(), obj.getGradeToSign(), obj.getGradeToExec()),
	_target(obj._target) {} ;

ShrubberyCreationForm::~ShrubberyCreationForm(void) {} ;

std::string ShrubberyCreationForm::getTarget(void) const {
	return _target;
}

ShrubberyCreationForm::BureauNotSignedException::BureauNotSignedException(void) 
	: BureauException("the form is not signed") {} ;

ShrubberyCreationForm::BureauNotExecutedException::BureauNotExecutedException(void) 
	: BureauException("the Bureaucrat grade is too low to execute Shrubbery creation") {} ;

bool 	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getIsFormSigned()) {
		throw BureauNotSignedException();
	}

	else if (executor.getGrade() > this->getGradeToExec()) {
		throw BureauNotExecutedException();
	}

	std::string 	filename(_target + "_shrubbery");
	std::ofstream	outfs(filename.c_str());

	if (!outfs.is_open())
		throw std::ios_base::failure("Could not create the file");

	outfs << "\n"
		<< "     ccee88oo                  ccee88oo                  ccee88oo             \n"
		<< "  C8O8O8Q8PoOb o8oo         C8O8O8Q8PoOb o8oo         C8O8O8Q8PoOb o8oo       \n"
		<< " dOB69QO8PdUOpugoO9bD      dOB69QO8PdUOpugoO9bD      dOB69QO8PdUOpugoO9bD     \n"
		<< "CgggbU8OU qOp qOdoUOdcb   CgggbU8OU qOp qOdoUOdcb   CgggbU8OU qOp qOdoUOdcb   \n"
		<< "    6OuU  /p u gcoUodpP       6OuU  /p u gcoUodpP       6OuU  /p u gcoUodpP   \n"
		<< "      \\\\\\//  /douUP             \\\\\\//  /douUP             \\\\\\//  /douUP       \n"
		<< "        \\\\\\////                   \\\\\\////                   \\\\\\////           \n"
		<< "         |||/\\                     |||/\\                     |||/\\            \n"
		<< "         |||\\/                     |||\\/                     |||\\/            \n"
		<< "         |||||                     |||||                     |||||            \n"
		<< "   .....//||||\\....          .....//||||\\....          .....//||||\\....       \n"
		<< "  ..................        ..................        ..................      \n"
		<< " thanks to David Moore for the beautiful ASCII art I use for this exercise\n";
	outfs.close();
	return true;
};
