/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:07:07 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/03 15:35:46 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define  BUREAUCRAT_H

#include "GradeException.hpp"
#include <string>
#include <iostream>

class Bureaucrat 
{
	public:

	Bureaucrat(void);
	Bureaucrat(std::string name);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& obj);
	~Bureaucrat(void);

	std::string			getName() const;
	int					getGrade() const;
	bool				increment(const unsigned int levels);
	bool				decrement(const unsigned int levels);

	
	class GradeTooHighException : public GradeException {
		public:
		GradeTooHighException(void);
		GradeTooHighException(int grade);
		
	};
	
	class GradeTooLowException : public GradeException {
		public:
		GradeTooLowException(void);
		GradeTooLowException(int grade);
	};
	
	
	private:
	
	Bureaucrat&	operator=(const Bureaucrat& obj);
	
	const static int	_maxgrade = 1;
	const static int	_mingrade = 150;

	const std::string	_name;
	int					_grade;
	
	bool				_check_grade(int grade) const;
	

};

// include << overload over cout stream
std::ostream&		operator<<(std::ostream& ostream, Bureaucrat const &obj);

#endif