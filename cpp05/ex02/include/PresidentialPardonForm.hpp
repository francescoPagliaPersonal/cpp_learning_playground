/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:27:16 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/07 19:27:18 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# define PPF_SIGN 25
# define PPF_EXEC 5

#include "AForm.hpp"


class PresidentialPardonForm : public AForm 
{
	public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	~PresidentialPardonForm(void);

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
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& obj);
	PresidentialPardonForm(void);

	std::string		_target;
};

#endif
 
