/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:27:33 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/07 19:33:00 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# define SCF_SIGN 145
# define SCF_EXEC 137

#include "AForm.hpp"


class ShrubberyCreationForm : public AForm 
{
	public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
	~ShrubberyCreationForm(void);

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
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& obj);
	ShrubberyCreationForm(void);

	std::string		_target;
};

#endif
 
