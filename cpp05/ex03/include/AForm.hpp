/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:44:07 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/03 15:56:13 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include "bureauLimits.h"
#include "BureauException.hpp"
#include <string>
#include <iostream>

class Bureaucrat ;

class AForm 
{
	public:

	AForm(std::string name, int signingGrade, int executingGrade);
	AForm(const AForm& obj);
	virtual ~AForm(void);
	
	std::string		getName() const;
	int				getGradeToSign() const;
	int				getGradeToExec() const; 
	bool			getIsFormSigned() const;
	bool			beSigned(const Bureaucrat& obj);
	
	virtual bool 	execute(Bureaucrat const & executor) const = 0;
	
	class GradeTooHighException : public BureauException {
		public:
		GradeTooHighException(void);
		GradeTooHighException(int value);
	} ;
	
	class GradeTooLowException : public BureauException {
		public:
		GradeTooLowException(void);
		GradeTooLowException(int value);
	} ;

	class FormSignedException : public BureauException {
		public:
		FormSignedException(void);
	} ;

	private:
	
	AForm(void);
	AForm&	operator=(const AForm& obj);
	
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExec;
	
	bool				_issigned;
	
	int					_isValidGrade(int value) const;
};

std::ostream&		operator<<(std::ostream& ostream, const AForm& obj);
std::ostream&		operator<<(std::ostream& ostream, const AForm* obj);
#endif
/*
Let’s create a AForm class. It has:
• A constant name.
• A boolean indicating whether it is signed (at construction, it is not).
• A constant grade required to sign it.
• A constant grade required to execute it.
All these attributes are private, not protected.
*/