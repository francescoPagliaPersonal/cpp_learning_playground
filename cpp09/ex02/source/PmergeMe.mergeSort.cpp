/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.mergeSort.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:13:37 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/05 15:25:35 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstddef>
#include <vector>

typedef std::deque<int>::size_type	deq_id;

// std::vector<PmergeMe::winner_s> & PmergeMe::_merge(std::vector<winner_s> & winners )
// {
// 	if (winners.size() < 2)
// 		return winners;
	
// 	typedef std::vector<winner_s>::size_type	win_id;
	
// 	std::vector<pair_s>		pairs;
// 	for (win_id id = 0; id + 1 < winners.size(); id += 2) {
// 		pair_s couple;
// 		if (winners[id].value > winners[id + 1].value) {
// 			couple.winner = winners[id].value;
// 			couple.looser = winners[id + 1].value;
// 		}
		
// 	}
	
	
// }

void PmergeMe::print_pairs_info(std::vector<numid_s> const & looser, std::vector<numid_s> const & winner)
{
	for (size_t i = 0; i < winner.size(); ++i)
	{
		std::cout << winner[i].value << "\t";	
	}
	std::cout << std::endl;
	for (size_t i = 0; i < looser.size(); ++i)
	{
		std::cout << looser[i].value << "\t";	
	}
	std::cout << std::endl;
	for (size_t i = 0; i < winner.size(); ++i)
	{
		std::cout << *(--winner[i].index.end()) << "\t";	
	}
	std::cout << std::endl;
}

void PmergeMe::compare_pairs(std::vector<numid_s> & incoming)
{
	if (incoming.size() < 2)
		return ;
	
	std::vector<numid_s>	looser;
	std::vector<numid_s>	winner;
	
	numid_s					reminder;
	
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
		looser.push_back(*(--incoming.end()));
	incoming = winner;
	print_pairs_info(looser, winner);
	compare_pairs(winner);
	
}

int PmergeMe::mergeSort(std::vector<int> & db) 
{
	std::vector<numid_s>	winner;
	std::vector<numid_s>	looser;
	
	numid_s					reminder;
	
	if (_sourceItems.size() % 2 != 0)
		reminder.value = *(--_sourceItems.end());
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
	print_pairs_info(looser, winner);
	compare_pairs(winner);
	
	_vItems.push_back(reminder.value);
	db.push_back(reminder.value);
	return 1;
}
