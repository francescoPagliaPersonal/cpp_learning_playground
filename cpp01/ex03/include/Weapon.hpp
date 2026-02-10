/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:50:07 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/10 10:16:54 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>

class Weapon
{
	public:

	Weapon(std::string wtype);
	~Weapon(void);

	const std::string&	getType(void) const;
	void				setType(std::string type);

	private:

	std::string		_type;
};

#endif
