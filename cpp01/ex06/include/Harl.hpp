/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:20:12 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/11 15:34:13 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <iostream>
# include <string>

	

class Harl 
{
	public:

	enum e_levels {
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		LEV_MAX	
	};

	Harl(void);
	~Harl(void);
	void	complain(std::string level);

	private:
	
	typedef struct s_compl
	{
		std::string	key;
		void		(Harl::*f)(void);
	} t_compl;
	
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);
	
	t_compl _complaints[LEV_MAX];
};

#endif
