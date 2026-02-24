/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:04:22 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/24 14:22:54 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

class Cat : public Animal
{

	public:

	Cat(void);
	Cat(const Cat& obj);
	Cat& operator=(const Cat& obj);
	~Cat(void);

	virtual std::string		getType(void) const;
	virtual void			makeSound(void) const;

	
	private:
	
	std::string		_type;
	Brain 			*ideas;
};

#endif
