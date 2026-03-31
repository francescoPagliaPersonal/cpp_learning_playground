/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeException.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:21:18 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/31 17:35:43 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>

class GradeException : public std::exception
{
	public:
	GradeException(std::string msg); 
	virtual ~GradeException();
	
	const char*		what() const throw();
	
	
	protected:
	std::string		_msg;

};
