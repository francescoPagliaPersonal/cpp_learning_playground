#include "header.hpp"


void printchain(std::vector<node_s> container)
{
	vec_id	id;
	for (id = 0; id < container.size(); ++id)
		std::cout << container[id].value << "\t";
	std::cout << std::endl;
}

void printVectorNode_s(std::string title, std::vector<node_s> container)
{
	vec_id	id;
	std::cout << title ;
	for (id = 0; id < container.size(); ++id)
		std::cout << container[id].value << " ";
	std::cout << std::endl;
}

void printVectorInt(std::string title, std::vector<int> container)
{
	vec_id	id;
	std::cout << title ;
	for (id = 0; id < container.size(); ++id)
		std::cout << container[id] << " ";
	std::cout << std::endl;
}
void printchainR(std::vector<node_s *> container, node_s *reminder)
{
	vec_id	id;
	for (id = 0; id < container.size(); ++id)
		std::cout << container[id]->value << "\t";
	if (reminder != NULL)
		std::cout << "(" << reminder->value << ")" ;
	std::cout << std::endl;
}

void printChildPar(std::vector<node_s> container)
{
	printchain(container);
	vec_id	id;
	for (id = 0; id < container.size(); ++id) {
		if (container[id].parent != NULL)
			std::cout << container[id].parent->value << "\t";
		else
			std::cout << "  \t";
	}
	std::cout << std::endl;

	for (id = 0; id < container.size(); ++id) {
		std::cout << container[id].wins << "\t";
	}
	std::cout << std::endl;
}

void printWinnerList(std::string title, node_s * winList)
{
	if (winList == NULL)
		return;
	
	std::cout << title ;
	
	node_s * tmp = winList;
	while (tmp != NULL) {
		std::cout << tmp->value << " ";
		tmp = tmp->next;
	}
	std::cout << std::endl;
}