/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:40:24 by fpaglia           #+#    #+#             */
/*   Updated: 2026/04/22 12:51:56 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <deque>
#include <iostream>

int main(void)
{
	Span myobj(500);
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	std::deque<int> test;
	for (int i = 0; i < 10; ++i)
		test.push_back(arr[i]);

	myobj.addNumber(46);
	myobj.addRange(test, test.begin(), test.end());
	std::cout << myobj << std::endl;
	return 0;	
}
