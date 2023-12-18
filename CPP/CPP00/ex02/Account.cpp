/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodos-sa <jodos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:12:33 by jodos-sa          #+#    #+#             */
/*   Updated: 2023/12/18 15:07:13 by jodos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* INFO First part print the amount and create accounts
//* INFO Second part print the resume
//* INFO Third part print the deposits
//* INFO Fourth part print the resume
//* INFO Fifth part print the witdhrawals
//* INFO Sixth part print the resume
//* INFO Seventh part close the accounts
//* INFO [19920104_091532] == [YYYYMMDD_HHMMSS]

#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	time_t rawtime;
    struct tm * timeinfo;
    char buffer [20];
    buffer[19] = '\0';

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,19,"[%Y%m%d_%H%M%S] ",timeinfo);
    std::cout << buffer;
}


Account::Account(int initial_deposit)
{
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount <<";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount <<";";
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
				<< "total:" << _totalAmount << ";"
				<< "deposits:" << _totalNbDeposits << ";"
				<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::displayStatus() const
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount <<";"
				<< "deposit:" << deposit << ";" << std::flush;
	_amount += deposit;
	std::cout << "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	if (_amount - withdrawal < 0)
	{
		std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount <<";"
				<< "withdrawal:" << "refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount <<";"
				<< "withdrawal:" << withdrawal << ";" << std::flush;
	_amount -= withdrawal;
	std::cout << "amount:" << _amount << ";"
				<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

