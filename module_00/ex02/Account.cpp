/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:31 by digoncal          #+#    #+#             */
/*   Updated: 2023/11/08 11:36:31 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account( int initial_deposit )
{
	Account::_nbAccounts += 1;
	this->_accountIndex = _nbAccounts - 1;
	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
			  << this->_amount << ";created" << std::endl;
}

Account::~Account( void )
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:"
			  << this->_amount << ";closed" << std::endl;
}


int 	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int 	Account::getTotalAmount()
{
	return (_totalAmount);
}

int 	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int 	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}


bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;

	p_amount = this->checkAmount();
	_displayTimestamp();
	if (withdrawal > 0 && withdrawal <= p_amount)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals += 1;

		std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount
				  << ";withdrawal:" << withdrawal << ";amount:" << this->checkAmount()
				  << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << p_amount
			  << ";withdrawal:refused" << std::endl;
	return false;
}

void	Account::makeDeposit( int deposit )
{
	int	p_amount;

	if (deposit <= 0)
		return ;
	p_amount = this->checkAmount();
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;

	_displayTimestamp();
	std::cout << "index:"<< this->_accountIndex << ";p_amount:" << p_amount
			  << ";deposit:" << deposit << ";amount:" << this->checkAmount()
			  << ";nb_deposits:" << this->_nbDeposits << std::endl;

}

void	Account::_displayTimestamp( void )
{
	std::time_t	c_time = std::time(0);
	std::tm*	time = std::localtime(&c_time);

	std::cout << "[" << 1900 + time->tm_year << 1 + time->tm_mon << time->tm_mday
			  << "_" << time->tm_hour << time->tm_min << time->tm_sec << "] ";
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:"
			  << Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;

}

void	Account::displayStatus( void ) const
{
		_displayTimestamp();
		std::cout << "index:"<< this->_accountIndex << ";amount:" << this->_amount
				  << ";deposits:" << this->_nbDeposits << ";withdrawals:"
				  << this->_nbWithdrawals << std::endl;
}
