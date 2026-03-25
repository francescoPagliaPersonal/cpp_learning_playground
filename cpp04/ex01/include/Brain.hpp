/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:13:40 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/24 17:22:47 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_H
# define BRAIN_H

# ifndef MAX_STRINGS
#  define MAX_STRINGS 100
# endif

#include "debug.h"
#include <iostream>
#include <sstream>
#include <string>

class Brain 
{
	public:
	
	Brain(void);
	Brain(const Brain& obj);
	Brain& operator=(const Brain& obj);
	~Brain(void);
	
	const std::string&	getAnIdea(unsigned int id) const;
	bool				setAnIdea(unsigned int id, const std::string& idea);
	
	private:
	
	std::string			ideas[MAX_STRINGS];
	static std::string	defaultIdea;
};

#endif