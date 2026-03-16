/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:07:07 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/16 15:07:09 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Bureaucrat 
{
	public:

	Bureaucrat(void);
	Bureaucrat(const Bureaucrat& obj);
	~Bureaucrat(void);
	Bureaucrat&	operator=(const Bureaucrat& obj);

	std::string			getName() const;
	int					getGrade() const;
	int					promote(const unsigned int levels);
	int					demote(const unsigned int levels);

	
	private:
	
	static int			_maxgrade = 1;
	static int			_mingrade = 150;

	const std::string	_name;
	int					_grade;
	
	const std::string	_report() const;

	/* exceptions to be studied:
	Bureaucrat::GradeTooHighException
	Bureaucrat::GradeTooLowException
	*/

}


// include << overload over cout stream