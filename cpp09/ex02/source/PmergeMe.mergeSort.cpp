/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.mergeSort.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:13:37 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/05 18:02:38 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstddef>
#include <vector>


void PmergeMe::print_pairs_info(std::vector<numid_s> const & looser, std::vector<numid_s> const & winner, int level)
{
	std::cout << "ITERATION: [" << level << "]" << "\nwinner:\t";
	for (size_t i = 0; i < winner.size(); ++i)
	{
		std::cout << winner[i].value << "\t";	
	}
	std::cout << std::endl;
	std::cout << "looser:\t";

	for (size_t i = 0; i < looser.size(); ++i)
	{
		std::cout << looser[i].value << "\t";	
	}
	std::cout << std::endl;
	std::cout << "index :\t";
	for (size_t i = 0; i < winner.size(); ++i)
	{
		for (vec_id id = 0; id < winner[i].index.size(); ++id)
			std::cout << winner[i].index[id] << " ";
		std::cout << "\t";	
	}
	std::cout << "\n" << std::endl;
}


void	PmergeMe::_insert_looser(std::vector<numid_s> & container, vec_it start, vec_it end, numid_s num) {
	if (end - start == 1) {
		if (num.value > end->value) {
			container.insert(end + 1, num);
		}
		else {
			num.value < start->value 
				? container.insert(end, num) 
				: container.insert(start, num);
			_vCounter++;
		}
		_vCounter++;
		return ;
	}
	else {
		if (container.at((end - start) / 2).value > num.value)
			_insert_looser(container, start + ((end - start) / 2), end, num);
		else
			_insert_looser(container, start, end - ((end - start) / 2), num);
		_vCounter++;
	}
}

void PmergeMe::_insert_array(std::vector<numid_s> & container, vec_id id_start, vec_id id_end, std::vector<numid_s> & winner, std::vector<numid_s> & looser ) {
	while (id_end >= id_start) {
		container.push_back(winner[id_end]);
		_insert_looser(container, container.begin(), container.end() -1, looser[id_end]);
		--id_end;
	}
}

void PmergeMe::_compare_pairs(std::vector<numid_s> & incoming, int level)
{
	if (incoming.size() < 2) 	
		return ;
	
	std::vector<numid_s>	looser;
	std::vector<numid_s>	winner;
	
	// build the pairs --------------> 
	for (vec_id id = 0; id + 2 <= incoming.size(); id += 2) {
		if (incoming[id].value > incoming[id + 1].value) {
			looser.push_back(incoming[id + 1]);
			incoming[id].index.push_back(id / 2);
			winner.push_back(incoming[id]);
		}
		else {
			looser.push_back(incoming[id]);
			incoming[id + 1].index.push_back(id / 2);
			winner.push_back(incoming[id + 1]);
		}
		_vCounter++;
	}
	if (incoming.size() % 2 != 0)
		looser.push_back(incoming.back());
	
	print_pairs_info(looser, winner, level);

	// execute recursion --------------> 
	_compare_pairs(winner, level + 1);
	
	
	// insert on return --------------->
	std::vector<numid_s> tmp;
	vec_id id = 0;
	tmp.push_back(looser[id]);
	tmp.push_back(winner[id]);
	++id;

	// TODO: resolve the growth of the array id!!!
	std::cout << "tmp size: " << tmp.size() << " incoming size: " << incoming.size() << std::endl;
	while (id < incoming.size() - 1) {
		vec_id id_end   = (2 * ++id) - 1 > incoming.size() ? (incoming.size() - 1) : (2 * id - 1);
		std::cout << "id: " << id << " id_end: " << id_end << std::endl;
		_insert_array(tmp, id, id_end, winner, looser);
		id = id_end;
	}
	incoming = tmp;
	print_pairs_info(std::vector<numid_s>(), tmp, level);
}

int PmergeMe::mergeSort(std::vector<int> & db) 
{
	std::vector<numid_s>	winner;
	std::vector<numid_s>	looser;
	int 					level = 0;
	numid_s					reminder;
	
	if (_sourceItems.size() % 2 != 0)
		reminder.value = _sourceItems.back();
	for (vec_id id = 0; id + 2 <= _sourceItems.size(); id += 2) 
	{
		if (_sourceItems[id] > _sourceItems[id + 1]){
			looser.push_back(numid_s( _sourceItems[id + 1]));
			winner.push_back(numid_s( _sourceItems[id], id / 2));
		}
		else {
			looser.push_back(numid_s( _sourceItems[id]));
			winner.push_back(numid_s( _sourceItems[id + 1], id / 2));
		}
		_vCounter++;
	}
	if (reminder.value > -1)
		looser.push_back(reminder);
	print_pairs_info(looser, winner, 0);
	_compare_pairs(winner, ++level);
	
	_vItems.push_back(reminder.value);
	db.push_back(reminder.value);
	return 1;
}
