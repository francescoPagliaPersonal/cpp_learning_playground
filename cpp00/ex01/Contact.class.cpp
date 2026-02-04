/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:00:13 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/04 16:15:14 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <string>

Contact::Contact(void) : name(""), surn(""), nick(""), phon(""), secr("") {}

Contact::~Contact(void) {}

std::string Contact::get_field(enum e_fields id) const
{
	if (id < MAX_FIELD)
		return (param[id]);
	return ("");
}

bool	Contact::set_field(enum e_fields id, std::string& str)
{
	if (id < 0 || id > MAX_FIELD)
		return (false);
	param[id].assign(str);
	return (true)
}