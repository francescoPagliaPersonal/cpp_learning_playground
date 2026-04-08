/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:06:17 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/08 16:49:59 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::t_dictForm Intern::_entryMap[MAXFORM] = {
		{"Shrubbery Creation", createShrubbery }, 
		{"Robotomy Request", createRobotomy }, 
		{"Presidential Pardon", createPresidential }, 
};

Intern::Intern(void) {} ;

Intern::~Intern(void) {} ;

AForm *Intern::makeForm(std::string label, std::string target) {
	AForm *tmp;
	switch (Intern::getCase(label)) {
		case 0: 
			tmp = new ShrubberyCreationForm(target);
			break ;
		case 1: 
			tmp = new RobotomyRequestForm(target);
			break ;
		case 2:
			tmp = new PresidentialPardonForm(target);
			break ;
		default :
			tmp = NULL;
	}
	if (!tmp)
		std::cout << "\nERROR\nIntern tried to create\nForm: " << label
				<< "\ntarget: " << target << "\n"
				<< "Select Form is not available please choose one of those options:\n"
				<< "- \"Shrubbery Creation\"\n"
				<< "- \"Robotomy Request\"\n"
				<< "- \"Presidential Pardon\"\n\n"
				<< "...Null Form returned.\n" << std::endl;
	else
		std::cout << "Intern creates " << tmp->getName() << " Form" << std::endl;
	return tmp;
}

int	Intern::getCase(std::string label) {
	int i = 0;
	while (i < 3)
	{
		if (label == forms[i])
			return i;
		i++;
	}
	return -1;
}

AForm * Intern::createShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}


AForm * Intern::createRobotomy(std::string target) {
	return new ShrubberyCreationForm(target);
}


AForm * Intern::createPresidential(std::string target) {
	return new ShrubberyCreationForm(target);
}

