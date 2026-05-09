/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 09:31:43 by fpaglia           #+#    #+#             */
/*   Updated: 2026/05/08 15:07:51 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void PmergeMe::_printIterable(std::string title, T const & obj) {
	std::cout << "\nPRINTING "<< title << ": "<< std::endl;
	typename T::const_iterator it = obj.begin();
	typename T::const_iterator ite = obj.end();
	if (it == ite)
		return;
	--ite;
	while (it != ite )
	{
		std::cout << *it << ", ";
		++it;
	}
	std::cout << *it << "." << std::endl;
}

template<typename T>
void PmergeMe::printchainR(T container, node_s *reminder)
{
	typename T::size_type	id;
	for (id = 0; id < container.size(); ++id)
		std::cout << container[id]->value << "\t";
	if (reminder != NULL)
		std::cout << "(" << reminder->value << ")" ;
	std::cout << std::endl;
}

template<typename T>
void PmergeMe::printVectorNode_s(std::string title, T container)
{
	typename T::size_type	id;
	std::cout << title ;
	for (id = 0; id < container.size(); ++id)
		std::cout << container[id]->value << " ";
	std::cout << std::endl;
}