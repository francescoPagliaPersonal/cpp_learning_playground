/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 12:53:28 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/26 13:17:05 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_H
# define IMATERIASOURCE_H

# include <string>

class IMateriaSource
{
	public:
	IMateriaSource(void);
	IMateriaSource(std::string const & type);
	IMateriaSource(const IMateriaSource& obj);
	IMateriaSource& operator=(const IMateriaSource& obj);
	virtual ~IMateriaSource(void);

	protected:

	private:
};

#endif
