# include "Account.hpp"
# include <iostream>
# include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {

	_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	_amount = initial_deposit;
	Account::_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void ) {

	Account::_nbAccounts--;
	Account::_totalAmount -= _amount;

	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::_displayTimestamp( void ) {

	std::time_t		t = std::time(0);

	std::tm*	tm_ptr = std::localtime(&t);
	char	buffer[18];

	std::strftime(buffer, 18, "[%Y%m%d_%H%M%S]", tm_ptr);
	std::cout << buffer;
}

int	Account::getNbAccounts( void ) {

	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {

	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {

	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {

	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ){

	Account::_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {

	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
	Account::_totalAmount += deposit;
	_amount += deposit;
	_nbDeposits++;
	Account::_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal;
	if (withdrawal > _amount) {

		std::cout << ";refused" << std::endl;
		return false;
	}
	Account::_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount( void ) const {

	return _amount;
}

void	Account::displayStatus( void ) const {

	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
