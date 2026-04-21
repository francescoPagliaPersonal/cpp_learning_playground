#include <cstddef>
#include <iterator>
#include <list>
#include <iostream>
#include <algorithm>

int main(void) 
{
	std::list<int> ciao;
	int num[] = {6,76,21,87};
	for (std::size_t i = 0; i < sizeof(num)/sizeof(num[0]); ++i)
		ciao.push_back(num[i]);
	std::_List_iterator<int> it = std::find(ciao.begin(),ciao.end(), 76);
	std::cout << *ciao.begin() << std::endl;
	std::cout << *it << std::endl;
	ciao.insert(++it, 42);
	for (it = ciao.begin(); it != ciao.end(); ++it)
		std::cout << *it << "  ";
	std::cout << std::endl;
}