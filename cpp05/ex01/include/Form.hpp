/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:44:07 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/08 13:16:28 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include "bureauLimits.h"
#include "GradeException.hpp"
#include <string>
#include <iostream>

class Bureaucrat ;

class Form 
{
	public:

	Form(std::string name, int signingGrade, int executingGrade);
	Form(const Form& obj);
	~Form(void);
	
	std::string		getName() const;
	int				getGradeToSign() const;
	int				getGradeToExec() const;
	bool			getIsFormSigned() const;
	bool			beSigned(const Bureaucrat& obj);
	
	class GradeTooHighException : public GradeException {
		public:
		GradeTooHighException(void);
		GradeTooHighException(int value);
	} ;
	
	class GradeTooLowException : public GradeException {
		public:
		GradeTooLowException(void);
		GradeTooLowException(int value);
	} ;

	class FormSignedException : public GradeException {
		public:
		FormSignedException(void);
	} ;

	private:
	
	Form(void);
	Form&	operator=(const Form& obj);
	
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExec;
	
	bool				_issigned;
	
	int					isValidGrade(int value) const;
};

std::ostream&		operator<<(std::ostream& ostream, Form const &obj);
std::ostream&		operator<<(std::ostream& ostream, const Form* obj);

#endif
/*
Let’s create a Form class. It has:
• A constant name.
• A boolean indicating whether it is signed (at construction, it is not).
• A constant grade required to sign it.
• A constant grade required to execute it.
All these attributes are private, not protected.
*/