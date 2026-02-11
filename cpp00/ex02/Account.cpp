/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaglia <fpaglia@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:02:10 by fpaglia           #+#    #+#             */
/*   Updated: 2026/02/11 18:15:44 by fpaglia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

// STATIC VALUES -------------------------------------------------------------/

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// CONSTRUCTORS  -------------------------------------------------------------/

Account::Account(int initial_deposit) 
	: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), 
		_nbWithdrawals(0)
{ 
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout 	<< " index:" << this->_accountIndex
			<< ";amount:" << this->_amount
			<< ";created" 
			<< std::endl;
};

Account::~Account(void) 
{
	_displayTimestamp();
	std::cout 		<< " index:" << this->_accountIndex
				<< ";amount:" << this->_amount
				<< ";closed" 
				<< std::endl;
};

Account::Account(void)
	:  _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0) 
{
	_nbAccounts++;
}

// FUNCTIONS -----------------------------------------------------------------/

int		Account::getNbAccounts(void) { return _nbAccounts; }

int		Account::getTotalAmount(void) { return _totalAmount; }

int 	Account::getNbDeposits(void) { return _totalNbDeposits; }

int		Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout 	<< " accounts:" << _nbAccounts
			<< ";total:" << _totalAmount
			<< ";deposits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals
			<< std::endl;
}

int		Account::checkAmount( void ) const { return _amount; };

void	Account::makeDeposit(int deposit)
{
	int	current_val = this->_amount;
	this->_amount += deposit;
	(this->_nbDeposits)++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout 	<< " index:" << this->_accountIndex
			<< ";p_amount:"	<< current_val
			<< ";deposit:"	<< deposit
			<< ";amount:"	<< this->_amount
			<< ";nb_deposits:" << this->_nbDeposits
			<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int difference = this->_amount - withdrawal;
	
	_displayTimestamp();
	std::cout 	<< " index:" << this->_accountIndex
			<< ";p_amount:"	<< _amount
			<< ";withdrawal:";

	if (difference < 0)
		std::cout << "refused" << std::endl;
	else {
		this->_amount -= withdrawal;
		(this->_nbWithdrawals)++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout	<< withdrawal
				<< ";amount:"	<< this->_amount
				<< ";nb_withdrawals:" << this->_nbDeposits
				<< std::endl;
	}
	return (difference > 0);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout 	<< " index:" << this->_accountIndex
			<< ";amount:"	<< this->_amount
			<< ";deposits:" <<this->_nbDeposits
			<< ";withdrawals:" << this->_nbWithdrawals
			<< std::endl;
}

void	Account::_displayTimestamp( void ) 
{
	if (DEBUG == 1) {
		std::cout << "[19920104_091532]";
		return ;
	}
	
	time_t timestamp;
	char output[50];
	struct tm * datetime;
	
	time(&timestamp);
	datetime = localtime(&timestamp);
	
	strftime(output, 50, "[%Y%m%d_%H%M%S]", datetime);
	std::cout << output ;

}
