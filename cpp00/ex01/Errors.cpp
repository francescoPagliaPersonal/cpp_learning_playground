/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:47:02 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/13 09:57:27 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Errors.h"

std::string		error_messages[E_MAX] = {
	"",
	"\nCTRL+D \"signal\" sent. Exiting now",
	"Non ascii character added, operation aborted.",
	"Not a valid phone number please use only:  \"0123456789.+\"",
	"ID not found"
};
