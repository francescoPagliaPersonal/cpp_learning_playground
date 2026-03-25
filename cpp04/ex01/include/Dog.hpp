/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:04:28 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/24 16:31:42 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>
# include "debug.h"

class Dog : public Animal
{

	public:

	Dog(void);
	Dog(const Dog& obj);
	Dog& operator=(const Dog& obj);
	~Dog(void);

	virtual void			makeSound(void) const;
	const std::string&		getIdea(unsigned int id) const;
	bool					changeIdea(unsigned int id, std::string idea);
	
	
	private:
	
	Brain 			*ideas;
};

#endif


