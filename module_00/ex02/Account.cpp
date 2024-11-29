#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account( int initial_deposit ){
	_nbAccounts += 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts - 1;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:";
	std::cout << _accountIndex;
	std::cout << ";amount:";
	std::cout << initial_deposit;
	std::cout << ";created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << " index:";
	std::cout << _accountIndex;
	std::cout << ";amount:";
	std::cout << _amount;
	std::cout << ";closed" << std::endl;
}

void Account::_displayTimestamp(void) {
    char buffer[20]; // YYYYMMDD_HHMMSS has 15 characters + 1 for null terminator

	std::cout << "[";
    std::time_t now = std::time(NULL);
    std::tm* localTime = std::localtime(&now);
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localTime);
    std::cout << buffer;
    std::cout << "]";
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << " accounts:";
	std::cout << Account::_nbAccounts;
	std::cout << ";total:";
	std::cout << Account::_totalAmount;
	std::cout << ";deposits:";
	std::cout << Account::_totalNbDeposits;
	std::cout << ";withdrawals:";
	std::cout << Account::_totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << " index:";
	std::cout << _accountIndex;
	std::cout << ";amount:";
	std::cout << _amount;
	std::cout << ";deposits:";
	std::cout << _nbDeposits;
	std::cout << ";withdrawals:";
	std::cout << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	int	p_amount = _amount;

	_amount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << " index:";
	std::cout << _accountIndex;
	std::cout << ";p_amount:";
	std::cout << p_amount;
	std::cout << ";deposit:";
	std::cout << deposit;
	std::cout << ";amount:";
	std::cout << _amount;
	std::cout << ";nb_deposits:";
	std::cout << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	int	p_amount = _amount;

	_displayTimestamp();
	std::cout << " index:";
	std::cout << _accountIndex;
	std::cout << ";p_amount:";
	std::cout << p_amount;
	std::cout << ";withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	_nbWithdrawals = 1;
	_amount -= withdrawal;
	_totalNbWithdrawals += 1;
	_totalAmount -= withdrawal;
	std::cout << withdrawal;
	std::cout << ";amount:";
	std::cout << _amount;
	std::cout << ";nb_withdrawals";
	std::cout << _nbWithdrawals << std::endl;
	return (true);
}
