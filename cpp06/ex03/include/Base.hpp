/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 09:58:37 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/15 10:31:52 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

class Base {
	public:
	virtual ~Base(void);
	
	static Base*	generate(void);
	static void		identify(Base* p);	
	static void		identify(Base& p);
};
#endif
