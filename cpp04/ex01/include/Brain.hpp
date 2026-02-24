/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 12:13:40 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/24 15:36:44 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BRAIN_H
# define BRAIN_H

# ifndef MAX_STRING
#  define MAX_STRING 100
# endif

#include <string>

class Brain 
{
	public:
	
	Brain(void);
	Brain(const Brain& obj);
	Brain& operator=(const Brain& obj);
	~Brain(void);
	
	bool		loadSentences(std::string filepath); // FIXME better to have a loop directly that opens the file?
	std::string	*getIdeas(void);
	
	private:
	
	std::string	ideas[MAX_STRING];
};

#endif