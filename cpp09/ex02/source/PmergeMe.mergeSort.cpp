/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.mergeSort.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:13:37 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/05 13:05:45 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstddef>
#include <vector>

typedef std::vector<int>::size_type	vec_id;
typedef std::deque<int>::size_type	deq_id;

std::vector<PmergeMe::winner_s> & PmergeMe::_merge(std::vector<winner_s> & winners )
{
	if (winners.size() < 2)
		return winners;
	
	typedef std::vector<winner_s>::size_type	win_id;
	
	std::vector<pair_s>		pairs;
	for (win_id id = 0; id + 1 < winners.size(); id += 2) {
		pair_s couple;
		if (winners[id].value > winners[id + 1].value) {
			couple.winner = winners[id].value;
			couple.looser = winners[id + 1].value;
		}
		
	}
	
	
}

int PmergeMe::mergeSort(std::vector<int> & db) {
	
	std::vector<winner_s>	winners;
	std::vector<pair_s>		pairs;
	
	for (vec_id id = 0; id + 2 < db.size(); id += 2) {
		
		pair_s couple;	
		if (db[id] > db[id + 1]){
			couple.looser = db[id + 1];
			couple.winner = db[id];
		}
		else {
			couple.looser = db[id];
			couple.winner = db[id + 1];
		}
		pairs.push_back(couple);
		_vCounter++;
	}
	typedef std::vector<pair_s>::size_type  pair_id;
	for (pair_id id = 0; id < pairs.size(); ++id )	
	{
		winner_s	info;
		info.index.push_back(id);
		info.value = pairs[id].winner; 
	}
	
	return 1;
}
