/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Setter.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 14:53:07 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/29 10:43:45 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTER_CLASS_H
# define  SETTER_CLASS_H

#include <iostream>

class Setter {

	public:
	
	Setter(int myval);
	~Setter(void);

	int		getVal(void) const;
	bool	setVal(int num);

	private:
	
	int		_val;
};

#endif
