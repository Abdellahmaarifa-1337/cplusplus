#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	print_time()
{
	std::time_t t = std::time(0);
	std::tm *now  = std::localtime(&t);
	std::cout << "[" << (now->tm_year + 1900);
	std::cout << std::setfill('0') << std::setw(2)<< now->tm_mon + 1;
	std::cout << now->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(6)
		<< ((now->tm_hour*60*60) + (now->tm_min * 60) + now->tm_sec)
		<< "] ";
}

Account::Account()
{
	_nbAccounts = 0;
	_totalAmount = 0;
	_totalNbDeposits = 0;
	_totalNbWithdrawals = 0;
};
Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	this->_nbAccounts++;
	print_time();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	_totalAmount += initial_deposit;
};

Account::~Account(void)
{
	print_time();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed"  << std::endl;
};

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
};
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
};
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
};
int	Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
};
// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
	print_time();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
};

void	Account::displayStatus( void ) const
{
	print_time();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
};

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	print_time();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
	
	_totalAmount += deposit;
	_totalNbDeposits++;
};


bool	Account::makeWithdrawal(int withdrawal)
{
	print_time();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (_amount >= withdrawal)
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		_amount -= withdrawal;
		std::cout << "amount:" << _amount << ";";
		_nbWithdrawals++;
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
};

int	Account::checkAmount(void) const
{
	return (_amount);
}