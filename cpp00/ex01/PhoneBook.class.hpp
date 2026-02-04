/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:45:38 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/04 14:12:48 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <iostream>
# include <string>
# include "Contact.class.hpp"
#include <cstdlib>

class PhoneBook {
	
	public:
	
	PhoneBook(void);
	~PhoneBook(void);
	
	void 		search(void) const;
	bool		add(void);
	static int	getid(void);

	private:
	
	static int	ids;
	Contact		entry[8];

	void		display_table(const Contact *entry, int idsize) const;
	void		display_contact(const Contact *entry, int id) const;

};
#endif
