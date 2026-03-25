/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:04:28 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/24 17:27:20 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "debug.h"
# include <iostream>
# include <string>


class Dog : public Animal
{

	public:

	Dog(void);
	Dog(const Dog& obj);
	Dog& operator=(const Dog& obj);
	~Dog(void);

	virtual void			makeSound(void) const;

};

#endif


