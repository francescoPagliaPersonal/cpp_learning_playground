/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:07:07 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/31 13:16:59 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
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
	Bureaucrat&	operator=(const Bureaucrat& obj);

	std::string			getName() const;
	int					getGrade() const;
	bool				increment(const unsigned int levels);
	bool				decrement(const unsigned int levels);

	
	class GradeTooHighException : public std::invalid_argument {
		public: 
		GradeTooHighException(std::string what_msg, int grade);
		int		getWrongGrade() const; 
		private:
		int		_futureGrade;
	};
	
	class GradeTooLowException : public std::invalid_argument {
		public: 
		GradeTooLowException(std::string what_msg, int grade);
		int		getWrongGrade() const; 
		
		private:
		int		_futureGrade;
	};
	
	private:
	
	const static int	_maxgrade = 1;
	const static int	_mingrade = 150;

	const std::string	_name;
	int					_grade;
	
	bool				_check_grade(int grade) const;
	

};

// include << overload over cout stream
std::ostream&		operator<<(std::ostream& ostream, Bureaucrat const &obj);