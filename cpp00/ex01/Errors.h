/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 14:46:57 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/06 14:46:58 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <string>

typedef enum e_return {
	OK,
	E_EOF,
	E_ASCII,
	E_PHONE,
	E_INDEX,
	E_MAX
} t_ret;

extern std::string		error_messages[];
# endif
