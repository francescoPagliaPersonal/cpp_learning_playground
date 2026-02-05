/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstCount.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:36:29 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/29 11:59:06 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InstCount.class.hpp"

int InstCount::count = 0;

InstCount::InstCount(void) {

	std::clog << "InstCount instance constructed" << std::endl;
	InstCount::count += 1;
}

InstCount::~InstCount(void) {

	std::clog << "InstCount instance destroyed" << std::endl;
	InstCount::count -= 1;
}

int	InstCount::getcount(void) {

	return (InstCount::count);
}
