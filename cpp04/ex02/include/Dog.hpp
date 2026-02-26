/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:04:28 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 11:28:44 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>
# include "debug.h"

class Dog : public AAnimal
{

	public:

	Dog(void);
	Dog(const Dog& obj);
	Dog& operator=(const Dog& obj);
	~Dog(void);

	virtual std::string			getType(void) const;
	virtual void				makeSound(void) const;
	virtual const std::string&	getIdea(unsigned int id) const;
	virtual bool				changeIdea(unsigned int id, std::string idea);
	virtual AAnimal*			clone() const;
	
	
	private:
	
	std::string		_type;
	Brain 			*ideas;
};

#endif


