/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:45:38 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/05 12:42:39 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <cstddef>
# include <iostream>
# include <string>
# include <cstdlib>

# include "Contact.class.hpp"
# include "Errors.h"

class PhoneBook {
	
	public:

	PhoneBook(void);
	~PhoneBook(void);
	
	void 		search(void) const;
	t_ret		add(void);
	static int	getid(void);

	private:
	
	static int	ids;
	Contact		_entry[8];

	void		display_table(const Contact *entry, int idsize) const;
	void		display_contact(const Contact *entry, int id) const;
	t_ret		set_field(Contact& entry, enum Contact::e_fields id, std::string& str);

};
#endif
