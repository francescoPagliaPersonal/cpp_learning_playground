/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InstCount.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 11:34:13 by fpaglia           #+#    #+#             */
/*   Updated: 2026/01/29 11:57:58 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTCOUNT_CLASS_H
#define  INSTCOUNT_CLASS_H

#include <iostream>

class InstCount {

	public:

	InstCount(void);
	~InstCount(void);

	static int	getcount(void);

	private:

	static int	count;
};

#endif
