/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Compare.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:44:49 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/29 11:14:13 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPARE_CLASS_H
# define  COMPARE_CLASS_H

#include <iostream>

class Compare {
	public:
	
	Compare(int num);
	~Compare(void);
	
	int		getval(void);
	void	setval(int num);
	int		check(Compare *cmp);

	private:

	int		_val;
};


#endif

