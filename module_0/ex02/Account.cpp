#include "Account.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

/*Ce qui est diffusé sur la sortie standard : 

A chaque fois, le timestamp sera émis.
1. Affichage de l'index de chacun des 8 comptes et de leur montant par le constructeur
suivie d'une phrase d'ouverture.
2. Synthèse affichant le nombre de comptes, combien l'ensemble des comptes représentent,
Le nombres de dépôt effectué de puis la création, le nombre de retrait effectué de puis la création grâce à Account::displayAccountsInfos().
3. Durant for_each, état de chacun des comptes grâce à Account::displayStatus.
4. Dans boucle for, affichage des dépôts. Consiste à afficher le montant précédent
l'opération, le dépot et a combien il s'élève, le nouveau montant et le nombre d'opération effectué. 
5. Répétition de l'étape 2
6. Répetition de l'étape 3
7. Répétition de l'étape 4 avec Withdrawal au lieu de deposit
8. Répétition de l'étape 2
9. Répétion de l'étape 3
10. Affichage de l'index de chacun des 8 comptes et de leur montant par le destructeur
suivie d'une phrase de cloture.*/

using std::cout;
using std::endl;

Account::Account( void )
{
	return;
}

Account::Account( int initial_deposit )
{
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = 0;
	
	this->_amount = initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	cout << "index:" << this->_accountIndex << ';';
	cout << "amount:" << this->_amount << ';';
	cout << "created" << endl;
	return;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	cout << "index:" << this->_accountIndex << ';';
	cout << "amount:" << this->_amount << ';';
	cout << "closed" << endl;
	return;
}

void	Account::_displayTimestamp( void )
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (buffer,80,"[%Y%m%d_%H%M%S] ",timeinfo);
	cout << buffer;
	return;
}

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	cout << "accounts:" << Account::getNbAccounts() << ';';
	cout << "total:" << Account::getTotalAmount() << ';';
	cout << "deposits:" << Account::getNbDeposits() << ';';
	cout << "withdrawals:" << Account::getNbWithdrawals() << endl;
	return;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "amount:" << this->_amount << ";";
	cout << "deposits:" << this->_nbDeposits << ";";
	cout << "withdrawals:" << this->_nbWithdrawals << endl;
	return;
}

void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	cout << "index:" << this->_accountIndex << ";";
	cout << "p_amount:" << this->_amount << ";";
	cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	cout << "amount:" << this->_amount << ";";	
	cout << "nb_deposits:" << this->_nbDeposits << endl;
	return;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal <= this->_amount)
	{
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_displayTimestamp();
		cout << "index:" << this->_accountIndex << ";";
		cout << "p_amount:" << this->_amount << ";";
		cout << "withdrawal:" << withdrawal << ";";
		this->_amount -= withdrawal;
		cout << "amount:" << this->_amount << ";";	
		cout << "nb_withdrawals:" << this->_nbWithdrawals << endl;
		return true;
	}
	else
	{
		Account::_displayTimestamp();
		cout << "index:" << this->_accountIndex << ";";
		cout << "p_amount:" << this->_amount << ";";
		cout << "withdrawals:refused" << endl;
		return false;
	}
}

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;
