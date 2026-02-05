/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InitLst.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:38:35 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/28 14:24:17 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INITLST_CLASS_H
# define INITLST_CLASS_H


#include <iostream>

class InitLst {

	public:

	int		i1;
	char	c1;
	float	f1;

			InitLst(int num, char word, float dotnum);
			~InitLst(void);
	void	report(void) const;

	private:

	int		_m1;
	int		_set_private(int a);

};

#endif
