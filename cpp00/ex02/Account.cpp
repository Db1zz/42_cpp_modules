#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
  : _accountIndex(_nbAccounts),  _amount(initial_deposit), _nbDeposits(1), _nbWithdrawals(0)
{
  _nbAccounts++;
  _totalAmount += initial_deposit;
  _totalNbDeposits++;
}

Account::~Account(void) {}

int Account::getNbAccounts() {
  return _nbAccounts;
}

int Account::getTotalAmount() {
  return _totalAmount;
}

int Account::getNbDeposits() {
  return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
  return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
  _displayTimestamp();
  std::cout << " accounts:" << _nbAccounts
            << ";total:" << _totalAmount
            << ";deposits:" << _totalNbDeposits
            << ";withdrawls:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
  _nbDeposits++;
  _amount += deposit;
  _nbDeposits++;

  _totalNbDeposits += deposit;
  _totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
  if (withdrawal > _amount) {
    return false;
  }
  _amount -= withdrawal;
  _nbWithdrawals++;

  _totalAmount -= withdrawal;
  _totalNbWithdrawals++;
}

int Account::checkAmount(void) const {
  return _amount;
}

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex
            << ";amount:" << _amount
            << ";deposits:" << _nbDeposits
            << "withdrawals" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
  std:time_t time = std::time(NULL);
  std::tm* curr_time = std::localtime(&time);
  std::cout << '[' << std::put_time(curr_time, "%Y%m%d_%H%M%S") << ']';
}
