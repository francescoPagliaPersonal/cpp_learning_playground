/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 12:20:12 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/10 15:20:30 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# include <iostream>
# include <string>

class Harl 
{
	public:
	
	Harl(void);
	~Harl(void);
	void	complain(std::string level);

	private:
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);

};

#endif
