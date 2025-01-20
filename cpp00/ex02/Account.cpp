#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
  : _accountIndex(_nbAccounts),  _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
  _displayTimestamp();
  std::cout << " index:" << _accountIndex
            << ";amount:" << _amount << ";created" << std::endl;

  _nbAccounts++;
  _totalAmount += initial_deposit;
}

Account::~Account(void) {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex
            << ";amount:" << _amount << ";closed" << std::endl;
}

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

  _displayTimestamp();
  std::cout << " index:" << _accountIndex
            << ";p_amount:" << _amount - deposit
            << ";deposit:" << deposit
            << ";amount:" << _amount
            << ";nb_deposits:" << _nbDeposits << std::endl;

  _totalAmount += deposit;
  _totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  if (withdrawal > _amount) {
    std::cout << " index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";withdrawal:refused" << std::endl;
    return false;
  } 
  _amount -= withdrawal;
  _nbWithdrawals++;
  std::cout << " index:" << _accountIndex
            << ";p_amount:" << _amount + withdrawal
            << ";withdrawal:" << withdrawal
            << ";amount:" << _amount
            << ";nb_withdrawals:" << _nbWithdrawals << std::endl;

  _totalAmount -= withdrawal;
  _totalNbWithdrawals++;
  return true;
}

int Account::checkAmount(void) const {
  return _amount;
}

void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << " index:" << _accountIndex
            << ";amount:" << _amount
            << ";deposits:" << _nbDeposits
            << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
  std::time_t time = std::time(NULL);
  std::tm* curr_time = std::localtime(&time);
  
  char time_str[1024];
  std::strftime(time_str, sizeof(time_str), "%Y%m%d_%H%M%S", curr_time);
  std::cout << "[" << time_str << "]";
}
