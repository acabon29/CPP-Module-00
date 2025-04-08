#include <iostream>
#include <stdio.h>
#include <unistd.h>


#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"


// std::string	_firstName;
// std::string	_lastName;
// std::string	_nickname;
// std::string	_phoneNumber;
// std::string	_darkestSecret;


void clearMemory(PhoneBook *phoneBook)
{
	for (size_t i = 0; phoneBook->getById(i) != NULL && i < NB_CONTACT; i++)
		delete phoneBook->getById(i);
	
	delete phoneBook;
}

void end_programme(PhoneBook *phoneBook)
{
	clearMemory(phoneBook);
	std::cout << "Merci d'avoir utiliser notre repertoir technologique !" << std::endl;
	_exit(1);
}

void setAttribute(PhoneBook *phoneBook, Contact *contact, std::string str,
				void (Contact::*methode)(std::string))
{
	std::string input;

	do {
		std::cout << str + " :" << std::endl;
		std::getline(std::cin, input);
		if (std::cin.eof())
			end_programme(phoneBook);
	} while (input.length() == 0);
	
	(contact->*methode)(input);
}

void addContact(PhoneBook *phoneBook)
{
	std::string input;
	Contact *contact;

	contact = new Contact();
	phoneBook->addContact(contact);

	std::cout << "Veuillez entrer les informations du contacte :" << std::endl;
	
	setAttribute(phoneBook, contact,
		"Prénom", &Contact::setFirstName);
	setAttribute(phoneBook, contact,
		"Nom de famille", &Contact::setLastName);
	setAttribute(phoneBook, contact,
		"Surnom", &Contact::setNickname);
	setAttribute(phoneBook, contact,
		"Numéro de téléphone", &Contact::setPhoneNumber);
	setAttribute(phoneBook, contact,
		"Son plus lourd secret", &Contact::setDarkestSecret);
}

void searchContact(PhoneBook *phoneBook)
{
	Contact *currentContact;
	std::string input;
	size_t i;
	bool that_will_false;

	if (phoneBook->getById(0) ==  NULL)
	{
		std::cout << "Erreur, aucun contact pour le moment !" << std::endl;
		return ;
	}

	std::cout << "Contacts :" << std::endl;
	for (i = 0; (currentContact = phoneBook->getById(i)) != NULL && i < NB_CONTACT; i++)
		currentContact->displayCol(i);

	that_will_false = false;
	do {
		do {
			if (that_will_false)
				std::cout << "Index invalide" << std::endl;
			std::cout << "Entrez le contact a afficher : ";	
			std::getline(std::cin, input);
			that_will_false = true;
		} while (input.length() != 1 || (input[0] < '0' || input[0] > '7'));
		currentContact = phoneBook->getById(input[0] - '0');
	} while (currentContact == NULL);
	
	std::cout << "Informations du contacte :" << std::endl;
	currentContact->displayAll();
}

int main(void)
{
	std::string input;
	PhoneBook *phoneBook;

	phoneBook = new PhoneBook();
	std::cout << "Bienvenu sur notre repertoir technologique !" << std::endl;
	
	while (1)
	{
		std::cout << "Entrez \"ADD\" pour ajouter un contacte." << std::endl;
		std::cout << "Entrez \"SEARCH\" chercher un contact." << std::endl;
		std::cout << "Entrez \"EXIT\" pour quitter de repertoire." << std::endl;
		
		std::getline(std::cin, input);

		if (input == "ADD")
			addContact(phoneBook);
		else if (input == "SEARCH")
			searchContact(phoneBook);
		else if (input == "EXIT" || std::cin.eof())
			end_programme(phoneBook);
	}
	clearMemory(phoneBook);
    return (0);
}
