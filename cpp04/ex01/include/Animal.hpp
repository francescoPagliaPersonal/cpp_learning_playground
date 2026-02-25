/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:04:12 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/25 16:11:55 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include <string>
# include "Brain.hpp"
# include "debug.h"
# include <cstddef>



class Animal {

	public:

	Animal(void);
	Animal(std::string type);
	Animal(const Animal& obj);
	Animal& operator=(const Animal& obj);
	virtual ~Animal(void);

	virtual std::string		getType(void) const;
	virtual void			makeSound(void) const;
	virtual const std::string&		getIdea(unsigned int id) const = 0;
	virtual bool					changeIdea(unsigned int id, std::string idea) = 0;
	
	private:
	
	std::string		_type;
	Brain 			*ideas;
};

#endif
