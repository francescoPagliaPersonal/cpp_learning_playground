/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.list2container.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 14:41:59 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/11 15:39:19 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> PmergeMe::_list2vector(node_s *list)
{
	std::vector<int> arr;

	if (list == NULL)
		return arr;
	
	
	node_s * tmp = list;
	while (tmp != NULL) {
		arr.push_back(tmp->value);
		tmp = tmp->next;
	}
	return arr;
}


std::deque<int> PmergeMe::_list2deque(node_s *list)
{
	std::deque<int> arr;

	if (list == NULL)
		return arr;
	
	
	node_s * tmp = list;
	while (tmp != NULL) {
		arr.push_back(tmp->value);
		tmp = tmp->next;
	}
	return arr;
}