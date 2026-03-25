/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:04:22 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/24 17:23:50 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "AAnimal.hpp"
# include "Brain.hpp"
# include "debug.h"
# include <iostream>
# include <string>

class Cat : public AAnimal
{

	public:

	Cat(void);
	Cat(const Cat& obj);
	Cat& operator=(const Cat& obj);
	~Cat(void);

	virtual void				makeSound(void) const;
	virtual const std::string&	getIdea(unsigned int id) const;
	virtual bool				changeIdea(unsigned int id, std::string idea);
	virtual AAnimal*			clone() const;

	
	private:
	
	Brain 			*ideas;
};

#endif
