/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:36:18 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/04 16:12:29 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>

class Contact {

	public:

	enum e_fields
	{
		NAME,
		SURNAME,
		NICK,
		PHONE,
		SECRET,
		MAX_FIELD
	};
	
	Contact(void);
	~Contact(void);

	std::string	get_field(enum e_fields id) const;
	bool		set_field(enum e_fields id, std::string& str);
	
	private:
	
	std::string param[MAX_FIELD];
	// std::string	name;
	// std::string	surn;
	// std::string	nick;
	// std::string	phon;
	// std::string	secr;
};

#endif
