/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test02.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:13:55 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/11 18:13:57 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <istream>

// Account hello(100);
#include <iostream>

int main(void)
{
	Account *accounts[3];

	accounts[0] = new Account(200);
	accounts[1] = new Account(43);
	accounts[2] = new Account(725);

	accounts[0]->displayAccountsInfos();

	accounts[0]->makeDeposit(50);
	accounts[0]->makeWithdrawal(70);
	accounts[0]->makeWithdrawal(190);

	accounts[0]->displayAccountsInfos();
	
	for (int i = 0; i < 3; ++i)
		delete accounts[i];
}
