/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyohn <sopka13@mail.ru>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 14:49:36 by eyohn             #+#    #+#             */
/*   Updated: 2021/06/29 00:44:35 by eyohn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include "Account.hpp"

int		Account::_nbAccounts;
int		Account::_totalAmount;
int		Account::_totalNbDeposits;
int		Account::_totalNbWithdrawals;

int		Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int		Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int		Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';';
	std::cout << "total:" << getTotalAmount() << ';';
	std::cout << "deposits:" << getNbDeposits() << ';';
	std::cout << "withdrawals:" << getNbWithdrawals() << ';' << std::endl;
}

Account::Account(int initial_deposit)						//constructor
{
	Account::_displayTimestamp();
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	_totalAmount += _amount;
	std::cout << "created" << std::endl;
	_nbAccounts++;
}

Account::~Account(void)										//destructor
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << _amount << ';';
	std::cout << "deposits:" << deposit << ';';
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits += _nbDeposits;
	std::cout << "amount:" << _amount << ';';
	std::cout << "nb_deposits:" << _nbDeposits << ';';
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "p_amount:" << _amount << ';';
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal:" << "refused" << std::endl;
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ';';
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "amount:" << _amount << ';';
	std::cout << "nb_withdrawal:" << _nbWithdrawals << ';';
	std::cout << std::endl;
	return (true);
}

int		Account::checkAmount(void) const
{
	return (0);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';';
	std::cout << "amount:" << _amount << ';';
	std::cout << "deposits:" << _nbDeposits << ';';
	std::cout << "withdrawals:" << _nbWithdrawals << ';';
	std::cout << std::endl;
}

void	Account::_displayTimestamp(void)
{
	struct tm *tp;
	time_t t;
	time(&t);												// get current time in second
	tp = localtime(&t);										// date and time in GMT format
	std::cout	<< std::put_time(tp, "[%Y%m%d_%H%M%S] ");
}