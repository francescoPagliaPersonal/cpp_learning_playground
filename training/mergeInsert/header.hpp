#ifndef HEADER_H
# define HEADER_H

# include <iostream>
# include <vector>
# include <cstddef>

# ifndef DEBUG
# define DEBUG 0
# endif

extern int __counter;


struct node_s {
	int		value;
	int		wins;
	node_s	*parent;
	node_s	*prev;
	node_s	*next;
	std::vector<node_s *>	childs;

	node_s(void) {value = -1; wins = 0; parent = NULL; prev = NULL; next = NULL;};
	node_s(int num) {value = num; wins = 0; parent = NULL; prev = NULL; next = NULL;};

};

typedef std::vector<node_s>::size_type		vec_id;
typedef std::vector<node_s *>::size_type	ptr_id;
typedef std::vector<int>::size_type			idx_id;

idx_id	findIndex(std::vector<node_s> & arr, int value);
std::vector<int> getJacobSequence(int count);

void printchain(std::vector<node_s> container);
void printchainR(std::vector<node_s *> container, node_s *reminder);
void printChildPar(std::vector<node_s> container);
void printVectorInt(std::string title, std::vector<int> container);
void printVectorNode_s(std::string title, std::vector<node_s> container);
void printWinnerList(std::string title, node_s * winList);


#endif // !HEADER_H
