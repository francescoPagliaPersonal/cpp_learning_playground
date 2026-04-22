/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ArrayException.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:13:04 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/17 11:13:06 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ArrayException.hpp"

ArrayException::ArrayException(const std::string& msg) 
		: std::exception(), 
		_msg(msg), 
		_value(0) {} ;

ArrayException::ArrayException(const std::string& msg, int value) 
		: std::exception(), 
		_msg(msg), 
		_value(value) {} ;

ArrayException::~ArrayException() throw() {};

const char*		ArrayException::what() const throw() {
	return (_msg.c_str());
}

int	ArrayException::getValue() const throw() {
	return (_value);
}

