/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureauException.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:40:36 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/07 17:05:10 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureauException.hpp"

BureauException::BureauException(const std::string& msg) 
		: std::exception(), 
		_msg(msg), 
		_value(0) {} ;

BureauException::BureauException(const std::string& msg, int value) 
		: std::exception(), 
		_msg(msg), 
		_value(value) {} ;

BureauException::~BureauException() throw() {};

const char*		BureauException::what() const throw() {
	return (_msg.c_str());
}

int	BureauException::getValue() const throw() {
	return (_value);
}

