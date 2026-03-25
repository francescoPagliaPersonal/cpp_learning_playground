/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:04:12 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/24 17:27:42 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include "debug.h"
# include <iostream>
# include <string>


class WrongAnimal {

	public:

	WrongAnimal(void);
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& obj);
	WrongAnimal& operator=(const WrongAnimal& obj);
	virtual ~WrongAnimal(void);

	std::string		getType(void) const;
	void			makeSound(void) const;
	
	
	protected:
	
	std::string		_type;
};

#endif
