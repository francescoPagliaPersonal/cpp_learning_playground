#include "Brain.hpp"
#include "Animal.hpp"
#include <string>


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


bool Brain::loadIdeas(std::string filename)
{
	std::string sentence;
	std::fstream file(filename.c_str());
	if (!file)
		return (false);

	int i = 0;
	while (i < MAX_STRINGS && std::getline(file, sentence))
	{
		ideas[i].assign(sentence);
		++i;
	}
	return (true);
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
	return ((ideas[id]));
}
