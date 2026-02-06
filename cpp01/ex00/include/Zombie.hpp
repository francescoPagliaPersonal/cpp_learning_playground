/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:45:41 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/06 14:45:49 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class Zombie {

	public:

	Zombie(std::string name);
	~Zombie(void);

	Zombie*	newZombie(std::string name);
	void	randomChump(std::string name);
	void	announce(void) const;

	private:
	std::string	name;
};

#endif // !ZOMBIE_H

