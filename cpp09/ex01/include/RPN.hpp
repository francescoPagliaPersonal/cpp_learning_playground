/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:59:50 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/05 10:43:58 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_H
# define RPN_H

#include <list>
# ifndef DEBUG
#  define DEBUG 0
# endif

# include <stack>


class RPN 
{
	public:
	
	static int		result(const char *str);
	
	
	private:
	
	RPN(void);
	RPN(const RPN & obj);
	~RPN(void);
	RPN& operator=(const RPN & obj);
	
	static std::stack<int, std::list<int> >		_items;
	
};

#endif