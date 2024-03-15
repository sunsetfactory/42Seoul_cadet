/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:11:53 by seokjyan          #+#    #+#             */
/*   Updated: 2024/03/11 19:15:25 by seokjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int		Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int		Account::getTotalAmount( void ) {
    return _totalAmount;
}

int		Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int		Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << endl;
}

Account::Account( int initial_deposit ) {
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();
    cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << endl;
}

Account::~Account( void ) {
    _nbAccounts--;
    _totalAmount -= _amount;

    _displayTimestamp();
    cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << endl;
}

void makeDeposit( int deposit ) {
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;

    _displayTimestamp();
    cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << endl;
}

bool makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    cout << "index:" << _accountIndex << ";p_amount:" << _amount;

    if (_amount >= withdrawal) {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << endl;
        return true;
    }
} else {
    cout << ";withdrawal:refused" << endl;
    return false;
}

int checkAmount( void ) const {
    return _amount;
}

void displayStatus( void ) const {
    _displayTimestamp();
    cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << endl;
}

void _displayTimestamp( void ) {
    cout << "[20240311_201532] ";
}