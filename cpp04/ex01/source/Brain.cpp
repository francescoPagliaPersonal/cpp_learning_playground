/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:13:53 by fpaglia           #+#    #+#             */
/*   Updated: 2026/03/24 17:22:18 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

std::string Brain::defaultIdea = "you reached the end of my brain";

Brain::Brain(void)
{
	for (int i = 0; i < MAX_STRINGS; ++i) 
	{
		std::ostringstream	name;
		name << "idea_" << i;
		ideas[i].assign(name.str());
	}
	if (DEBUG == 0)
		std::cout << "Brain Basic constructor called" << std::endl;
}

Brain::Brain(const Brain& obj)
{
	for (int i = 0; i < MAX_STRINGS; ++i)
		ideas[i].assign(obj.getAnIdea(i));
	if (DEBUG == 0)
		std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < MAX_STRINGS; ++i)
			ideas[i].assign(obj.getAnIdea(i));
	}
	if (DEBUG == 0)
		std::cout << "Brain assignment operator called" << std::endl;
	return (*this);
}

Brain::~Brain(void) {
	if (DEBUG == 0)
		std::cout << "Brain destructor called" << std::endl;
}

bool Brain::setAnIdea(unsigned int id, const std::string& idea)
{
	if (id < MAX_STRINGS)
	{
		ideas[id].assign(idea);
		return (true);
	}
	return (false);
}

const std::string&	Brain::getAnIdea(unsigned int id) const
{
	if (id < MAX_STRINGS)
		return ((ideas[id]));
	return defaultIdea;
}
