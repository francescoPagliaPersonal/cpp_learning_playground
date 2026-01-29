/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:36:18 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/29 17:47:50 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>

class Contact {

	public:
	
	Contact(void);
	~Contact(void);

	std::string	name;
	std::string	surn;
	std::string	nick;
	std::string	phon;
	std::string	secr;
};

#endif
