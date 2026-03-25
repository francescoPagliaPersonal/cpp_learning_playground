/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:04:12 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/24 17:19:59 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
# define ANIMAL_H

# include "debug.h"
# include <string>
#include <iostream>
#include <string>


class AAnimal {

	public:

	AAnimal(void);
	AAnimal(std::string type);
	AAnimal(const AAnimal& obj);
	AAnimal& operator=(const AAnimal& obj);
	virtual ~AAnimal(void);

	virtual std::string				getType(void) const;
	virtual void					makeSound(void) const = 0;
	virtual const std::string&		getIdea(unsigned int id) const = 0;
	virtual bool					changeIdea(unsigned int id, std::string idea) = 0;
	virtual AAnimal*				clone() const = 0;
	
	protected:
	
	std::string		_type;
};

#endif
