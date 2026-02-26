/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:04:12 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 09:55:10 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>
# include "debug.h"

class Animal {

	public:

	Animal(void);
	Animal(std::string type);
	Animal(const Animal& obj);
	Animal& operator=(const Animal& obj);
	virtual ~Animal(void);

	virtual std::string		getType(void) const;
	virtual void			makeSound(void) const;
	
	
	private:
	
	std::string				_type;
};

#endif
