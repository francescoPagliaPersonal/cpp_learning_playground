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

std::vector<PmergeMe::node_s *> 
PmergeMe::_buildRangeVector(node_s * first, node_s * last, 
							std::vector<node_s *>::size_type size)
{	
	std::vector<node_s *> arr;
	arr.reserve(size);
	
	node_s * tmp = first;
	
	while (tmp != last)
	{
		arr.push_back(tmp);
		tmp = tmp->next;
	}
	arr.push_back(last);
	return arr;
}


std::deque<PmergeMe::node_s *> 
PmergeMe::_buildRangeDeque(node_s * first, node_s * last, 
							std::deque<node_s *>::size_type size)
{	
	std::deque<node_s *> arr;
	(void)first;
	(void)size;
	
	arr.push_back(last);
	
	node_s * tmp = last->prev;
	
	while (tmp != NULL)
	{
		arr.push_front(tmp);
		tmp = tmp->prev;
	}
	return arr;
}
