/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 14:44:07 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/31 17:25:30 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Bureaucrat.hpp"
#include "GradeException.hpp"

class Form 
{
	public:

	Form(void);
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
		~GradeTooHighException(void);
	} ;
	class GradeTooLowException : public GradeException {
		public:
		GradeTooLowException(void);
		~GradeTooLowException(void);
	} ;

	private:
	Form&	operator=(const Form& obj);
	
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExec;
	
	bool				_issigned;
};

std::ostream&		operator<<(std::ostream& ostream, Form const &obj);

/*
Let’s create a Form class. It has:
• A constant name.
• A boolean indicating whether it is signed (at construction, it is not).
• A constant grade required to sign it.
• A constant grade required to execute it.
All these attributes are private, not protected.
*/