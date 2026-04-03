/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeException.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:40:36 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/03 12:57:27 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeException.hpp"

GradeException::GradeException(const std::string& msg) 
		: std::exception(), 
		_msg(msg), 
		_value(0) {} ;

GradeException::GradeException(const std::string& msg, int value) 
		: std::exception(), 
		_msg(msg), 
		_value(value) {} ;

GradeException::~GradeException() throw() {};

const char*		GradeException::what() const throw() {
	return (_msg.c_str());
}

int	GradeException::getValue() const throw() {
	return (_value);
}

