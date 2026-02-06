/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:47:02 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/06 14:47:04 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Errors.h"

std::string		error_messages[E_MAX] = {
	"",
	"EOF sent, message interrupted.",
	"Non ascii character added, operation aborted.",
	"Not a valid phone number please use only:  \"0123456789.+\"",
	"ID not found"
};
