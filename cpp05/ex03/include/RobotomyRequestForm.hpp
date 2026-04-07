/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:27:22 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/07 19:27:25 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# define RRF_SIGN 72
# define RRF_EXEC 45

#include "AForm.hpp"


class RobotomyRequestForm : public AForm 
{
	public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	~RobotomyRequestForm(void);

	virtual bool 	execute(Bureaucrat const & executor) const;
	std::string 	getTarget() const;
 
	class BureauNotSignedException : public BureauException {
		public:
		BureauNotSignedException(void);
	} ;
	
	class BureauNotExecutedException : public BureauException {
		public:
		BureauNotExecutedException(void);
	} ;

	private:
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& obj);
	RobotomyRequestForm(void);

	std::string		_target;
	static int		_attempt;
};

#endif
 
