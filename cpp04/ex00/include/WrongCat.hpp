/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:04:22 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 09:55:37 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"
#include <string>
# include "debug.h"


class WrongCat : public WrongAnimal
{

	public:

	WrongCat(void);
	WrongCat(const WrongCat& obj);
	WrongCat& operator=(const WrongCat& obj);
	~WrongCat(void);

	std::string		getType(void) const;
	void			makeSound(void) const;

	
	private:
	
	std::string		_type;
};

#endif
