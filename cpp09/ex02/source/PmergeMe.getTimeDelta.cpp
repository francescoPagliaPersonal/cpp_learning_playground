/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.getTimeDelta.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:51:01 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/12 11:57:12 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>
#include <sstream>
#include <sys/time.h>

std::string	PmergeMe::_getTimeDelta(struct timeval & begin) 
{
	struct timeval		end;
	std::stringstream	ss;
	gettimeofday(&end, 0);
	
	int seconds = static_cast<int>(end.tv_sec - begin.tv_sec);
	int endmicrosec = (seconds > 1 * 10e7) + end.tv_usec;
	int microsec =  endmicrosec - static_cast<int>(begin.tv_usec);
	if (!seconds) {
		ss << microsec;
		return ss.str();
	}

	ss << seconds;
	ss << std::setfill('0') << std::setw(6) << endmicrosec;
	return   ss.str();
}
