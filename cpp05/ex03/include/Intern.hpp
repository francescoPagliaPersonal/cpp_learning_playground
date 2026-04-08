/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:06:00 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/08 16:45:31 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include "AForm.hpp"
#include <string>

#define MAXFORM 3

class Intern 
{
	public:

	Intern(void);
	Intern(const Intern& obj);
	Intern& operator=(const Intern& obj);
	~Intern(void);
	
	static AForm		*makeForm(std::string label, std::string target);

	
	private:

	typedef AForm * (*formBuilder)(std::string);
	
	struct t_dictForm {
		const char		*key;
		formBuilder		funct;
	} ;

	static int			getCase(std::string label);
	static std::string	forms[3];
	static AForm *		createShrubbery(std::string target);
	static AForm *		createRobotomy(std::string target);
	static AForm *		createPresidential(std::string target);
	
	static t_dictForm	_entryMap[MAXFORM];
		
};


#endif
