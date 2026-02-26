/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:04:22 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 09:55:18 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include <string>
# include "debug.h"


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
};

#endif
