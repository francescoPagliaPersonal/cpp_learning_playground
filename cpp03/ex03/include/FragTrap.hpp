/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 16:22:31 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/19 16:49:33 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FragTrap_H
# define FragTrap_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(const FragTrap& obj);
	FragTrap& operator=(const FragTrap& obj);
	~FragTrap(void);
	
	void			highFivesGuys(void);
	void			attack(const std::string& target);
	void			report(void);

	
};

#endif

