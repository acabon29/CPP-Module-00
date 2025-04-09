#include "../includes/Account.hpp"

#include <iostream>
#include <ctime>
#include <iomanip>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( void ) 
{
	_displayTimestamp();

	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = 0;
}

Account::Account( int initial_deposit ) 
{
	_displayTimestamp();

	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
	_totalAmount += _amount;
	std::cout <<  "index:" << _accountIndex << ";amount:"
		<< _amount << ";created" << std::endl;
}

	// [19920104_091532] index:0;amount:47;closed
Account::~Account()
{
	_displayTimestamp();

	std::cout <<  "index:" << _accountIndex << ";amount:"
		<< _amount << ";closed" << std::endl;
}


// attributs :
// static int	_nbAccounts;
// static int	_totalAmount;
// static int	_totalNbDeposits;
// static int	_totalNbWithdrawals;
// int				_accountIndex;
// int				_amount;
// int				_nbDeposits;
// int				_nbWithdrawals;


// [19920104_091532]
// annee mois jour
// heure minutes, secondes
void	Account::_displayTimestamp( void )
{
	time_t timestamp;
	time(&timestamp);
	struct tm datetime = *localtime(&timestamp);

	// reverrifer ca
	std::cout << "[" << datetime.tm_year + 1900
			<< std::setfill('0')
			<< std::setw(2) << datetime.tm_mon
			<< std::setw(2) << datetime.tm_mday
			<< "_"
			<< std::setw(2) << datetime.tm_hour
			<< std::setw(2) << datetime.tm_min
			<< std::setw(2) << datetime.tm_sec << "] ";
}


	// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();

	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
			<< ";deposits:" << _totalNbDeposits
			<< ";withdrawals:" << _totalNbWithdrawals
			<< std::endl;
}

// index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus( void ) const
{
	_displayTimestamp();

	std::cout <<  "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits 
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int p_amount = _amount;

	_amount += deposit;
	_nbDeposits++;

	_totalNbDeposits++;
	_totalAmount += deposit;


	_displayTimestamp();

	// index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	std::cout <<  "index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";deposit:" << deposit 
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits << std::endl;
}


bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount = _amount;

	_displayTimestamp();

	std::cout <<  "index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";withdrawal:";

	if (p_amount - withdrawal < 0)
	{
		std::cout  << "refused" << std::endl;
		return ( false );
	}
	else 
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout  << withdrawal 
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	
	return ( true );
}


// int		checkAmount( void ) const;



// getters :
int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}
