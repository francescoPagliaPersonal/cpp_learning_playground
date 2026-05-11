#include "PmergeMe.hpp"
#include <deque>
#include <vector>

std::deque<PmergeMe::node_s>	PmergeMe::_vec2deq(std::vector<node_s> input) 
{
	std::deque<node_s>	tmp;

	std::vector<node_s>::size_type	id;
	for (id = 0; id < input.size(); ++id)
	{
		tmp.push_back(input[id]);
	}
	return tmp;
}