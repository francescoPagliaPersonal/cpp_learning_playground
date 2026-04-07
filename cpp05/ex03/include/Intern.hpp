/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:06:00 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/07 21:21:34 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include "AForm.hpp"

class Intern 
{
	public:

	Intern(void);
	Intern(const Intern& obj);
	Intern& operator=(const Intern& obj);
	~Intern(void);
	
	AForm		*makeForm(std::string label, std::string target);

	private:
	
	static int			getCase(std::string label);
	static std::string	forms[3];

};

#endif
