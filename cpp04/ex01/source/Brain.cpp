#include "Brain.hpp"
#include <fstream>
#include <string>

bool Brain::loadSentences(std::string filename)
{
	std::string sentence;
	std::fstream file(filename.c_str());
	if (!file)
		return (false);

	int i = 0;
	while (i < MAX_STRING && std::getline(file, sentence))
	{
		ideas[i] = sentence;
		++i;
	}
	return (true);
}

