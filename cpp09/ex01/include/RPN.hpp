/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:59:50 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/29 12:46:48 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_H
# define RPN_H

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <stack>
# include <string>
# include <iostream>

class RPN 
{
	public:
	
	static int		result(const char *str);
	
	
	private:
	
	RPN(void);
	RPN(const RPN & obj);
	~RPN(void);
	RPN& operator=(const RPN & obj);
	
	static std::stack<int>		_items;
	
};

#endif