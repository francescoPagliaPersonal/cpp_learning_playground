/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayException.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:13:22 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/17 11:13:24 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ArrayEXCEPTION_H
# define ArrayEXCEPTION_H

# include <exception>
# include <string>

class ArrayException : public std::exception
{
	public:
	ArrayException(const std::string& msg); 
	ArrayException(const std::string& msg, int value); 
	virtual ~ArrayException() throw();
	
	const char*		what() const throw();
	int				getValue() const throw();
	
	
	protected:
	std::string		_msg;
	int				_value;

	private:
	ArrayException(void);
};

#endif
