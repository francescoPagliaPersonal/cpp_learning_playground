/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:54:14 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/10 10:16:42 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

# include "Weapon.hpp"
# include <string>

class HumanA
{
	public:

	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);

	void			attack(void) const;

	private:
	std::string		_name;
	Weapon&			_weapon;
};

#endif
