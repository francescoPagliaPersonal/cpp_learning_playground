/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:36:18 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/05 12:43:22 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <string>
#include "Errors.h"

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
	std::string	get_field_name(enum e_fields id) const;
	t_ret		set_field(enum e_fields id, std::string& str);
	
	private:
	
	std::string	_param[MAX_FIELD];
	bool		sanitize_phone_number(std::string& str) const;
};

#endif
