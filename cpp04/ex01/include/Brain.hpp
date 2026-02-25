/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:13:40 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/25 14:41:24 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_H
# define BRAIN_H

# ifndef MAX_STRINGS
#  define MAX_STRINGS 100
# endif

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "debug.h"

class Brain 
{
	public:
	
	Brain(void);
	Brain(const Brain& obj);
	Brain& operator=(const Brain& obj);
	~Brain(void);
	
	bool				loadIdeas(std::string filepath); 
	const std::string&	getAnIdea(unsigned int id) const;
	bool				setAnIdea(unsigned int id, const std::string& idea);
	
	private:
	
	std::string			ideas[MAX_STRINGS];
};

#endif