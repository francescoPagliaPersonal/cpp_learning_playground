/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureauException.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:21:18 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/08 12:19:36 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUEXCEPTION_H
# define BUREAUEXCEPTION_H

# include <exception>
# include <string>

class BureauException : public std::exception
{
	public:
	BureauException(const std::string& msg); 
	BureauException(const std::string& msg, int value); 
	virtual ~BureauException() throw();
	
	const char*		what() const throw();
	int				getValue() const throw();
	
	
	protected:
	std::string		_msg;
	int				_value;

};

#endif
