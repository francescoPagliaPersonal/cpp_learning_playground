/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeException.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:21:18 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/03 12:17:00 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADEEXCEPTION_H
# define GRADEEXCEPTION_H

# include <exception>
# include <string>

class GradeException : public std::exception
{
	public:
	GradeException(const std::string& msg); 
	GradeException(const std::string& msg, int value); 
	virtual ~GradeException() throw();
	
	const char*		what() const throw();
	int				getValue() const throw();
	
	
	protected:
	std::string		_msg;
	int				_value;

};

#endif