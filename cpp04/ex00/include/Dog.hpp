/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:04:28 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 09:55:22 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include <string>
# include "debug.h"


class Dog : public Animal
{

	public:

	Dog(void);
	Dog(const Dog& obj);
	Dog& operator=(const Dog& obj);
	~Dog(void);

	virtual std::string		getType(void) const;
	virtual void			makeSound(void) const;
	
	
	private:
	
	std::string		_type;
};

#endif


