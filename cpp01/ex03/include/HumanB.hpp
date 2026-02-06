/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 23:00:22 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/06 23:00:23 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

# include "Weapon.hpp"
# include <string>

class HumanB
{
	public:

	HumanB(std::string name);
	~HumanB(void);

	void			attack(void) const;
	void			setWeapon(Weapon& myWeapon);

	private:
	std::string		name;
	Weapon*			weapon;
};

#endif

