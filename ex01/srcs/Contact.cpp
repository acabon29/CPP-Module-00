#include <iostream>
#include <iomanip>

#include "../includes/Contact.hpp"

// Attributs :
// std::string	_firstName;
// std::string	_lastName;
// std::string	_nickname;
// std::string	_phoneNumber;
// std::string	_darkestSecret;

// constructeur :
Contact::Contact(void) {}


// methodes :

void		Contact::displayCol(int index)
{
	std::string buffer;

	std::cout << std::setw(10) << index << "|";

	if (_firstName.length() > 10)
		std::cout << _firstName.substr(0, 9) + "." << "|";
	else
		std::cout << std::setw(10) << _firstName << "|";

	if (_lastName.length() > 10)
		std::cout << _lastName.substr(0, 9) + "." << "|";
	else
		std::cout << std::setw(10) << _lastName << "|";

	if (_nickname.length() > 10)
		std::cout << _nickname.substr(0, 9) + "." << std::endl;
	else
		std::cout << std::setw(10) << _nickname << std::endl;
}


void		Contact::displayAll()
{
	// modifier ca
	std::cout << "Prénom :" << std::endl;
	std::cout << _firstName << std::endl;
	std::cout << "Nom de famille :" << std::endl;
	std::cout << _lastName << std::endl;
	std::cout << "Surnom :" << std::endl;
	std::cout << _nickname << std::endl;
	std::cout << "Numéro de téléphone:" << std::endl;
	std::cout << _phoneNumber << std::endl;
	std::cout << "Son plus lourd secret :" << std::endl;
	std::cout << _darkestSecret << std::endl;
}




// setters :

void		Contact::setFirstName(std::string firstName)
{
	_firstName = firstName;
}

void		Contact::setLastName(std::string lastName)
{
	_lastName = lastName;
}

void		Contact::setNickname(std::string nickname)
{
	_nickname = nickname;
}

void		Contact::setPhoneNumber(std::string phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void		Contact::setDarkestSecret(std::string darkestSecret)
{
	_darkestSecret = darkestSecret;
}