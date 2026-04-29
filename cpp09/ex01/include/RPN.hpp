/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 09:59:50 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/29 10:26:47 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RPN_H
# define RPN_H

#include <stack>
#include <string>

class RPN 
{
	public:
	
	static std::string	parseInput(const char *str);
	static int			result(const std::string & input);
	
	
	private:
	
	RPN(void);
	RPN(const RPN & obj);
	~RPN(void);
	RPN& operator=(const RPN & obj);
	
	static std::stack<char>		_items;
	static std::stack<char>		_opQueue;
};

#endif