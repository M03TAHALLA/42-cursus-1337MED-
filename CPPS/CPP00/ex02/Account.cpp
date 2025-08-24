/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahalla <mtahalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:49:01 by mtahalla          #+#    #+#             */
/*   Updated: 2025/05/30 16:44:49 by mtahalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

			int Account::_nbAccounts = 0;
			int Account::_totalAmount= 0;
			int Account::_totalNbDeposits = 0;
			int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts++;
	_nbDeposits = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index :" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index :" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
    _nbAccounts--;
}

int Account::getNbAccounts()
{
	return _nbAccounts;	
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" 
	<< _nbAccounts << ";total:" 
	<< _totalAmount << ";deposits:" 
	<< _totalNbDeposits << ";withdrawals:" 
	<< _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    _amount += deposit;
    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	else
	{
		_totalAmount -= withdrawal;
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
}

int Account::checkAmount() const
{
    return _amount;
}


void Account::_displayTimestamp()
{
    std::time_t time = std::time(0);
    std::tm now = *std::localtime(&time);
    std::cout
        << "["
        << (now.tm_year + 1900)
        << std::setfill('0')
        << std::setw(2) << (now.tm_mon + 1)
        << std::setw(2) << now.tm_mday << "_"
        << std::setw(2) << now.tm_hour
        << std::setw(2) << now.tm_min
        << std::setw(2) << now.tm_sec
        << "] ";
}
