/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:45:41 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/10 10:15:50 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <sstream>
# include <string>

class Zombie {

	public:

	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);

	Zombie*	newZombie(std::string name);
	Zombie* zombieHorde( int N, std::string name );
	void	announce(void) const;
	void	setName(std::string name);

	private:
	std::string	_name;
};

#endif // !ZOMBIE_H

