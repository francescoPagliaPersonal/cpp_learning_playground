/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:04:22 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 11:28:39 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>
# include "debug.h"

class Cat : public AAnimal
{

	public:

	Cat(void);
	Cat(const Cat& obj);
	Cat& operator=(const Cat& obj);
	~Cat(void);

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
