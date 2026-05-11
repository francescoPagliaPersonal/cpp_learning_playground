/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.buildRange.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 13:22:47 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/11 15:41:36 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<PmergeMe::node_s *> PmergeMe::_buildRangeVector(node_s * last) 
{	
	std::vector<node_s *> arr;
	
	arr.push_back(last);
	
	node_s * tmp = last->prev;
	
	while (tmp != NULL)
	{
		arr.insert(arr.begin(), tmp);
		tmp = tmp->prev;
	}
	return arr;
}


std::deque<PmergeMe::node_s *> PmergeMe::_buildRangeDeque(node_s * last) 
{	
	std::deque<node_s *> arr;
	
	arr.push_back(last);
	
	node_s * tmp = last->prev;
	
	while (tmp != NULL)
	{
		arr.push_front(tmp);
		tmp = tmp->prev;
	}
	return arr;
}
