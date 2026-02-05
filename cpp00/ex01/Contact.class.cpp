/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:00:13 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/05 11:46:53 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "Errors.h"
#include <string>

static const char	*field_name[Contact::MAX_FIELD] = {
	"name",
	"surname",
	"nickname",
	"phone",
	"secret"
};

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string Contact::get_field(enum e_fields id) const
{
	if (id >= 0 && id < MAX_FIELD)
		return (param[id]);
	return ("");
}

std::string	Contact::get_field_name(enum e_fields id) const
{
	std::string str;	
	if (id >= 0 && id < MAX_FIELD)
		return (field_name[id]);
	return ("");
}


bool	Contact::sanitize_phone_number(std::string& str) const
{
	std::string	values(" 0123456789.+");
	if (str.find_first_not_of(values) == str.npos)
		return (true);
	return (false);
}

t_ret	Contact::set_field(enum e_fields id, std::string& str)
{
	if (id < 0 || id > MAX_FIELD)
		return (E_INDEX);
	if (id == PHONE && !sanitize_phone_number(str))
		return (E_PHONE);
	param[id].assign(str);
	return (OK);
}