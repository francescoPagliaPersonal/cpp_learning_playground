/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeException.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:40:36 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/31 17:35:31 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GradeException.hpp"

GradeException::GradeException(std::string msg) : _msg(msg) {} ;
GradeException::~GradeException() {} ;

const char*		GradeException::what() const throw() {
		return (_msg.c_str());
	}

