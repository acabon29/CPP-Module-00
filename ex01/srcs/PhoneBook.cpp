#include <iostream>
#include "../includes/PhoneBook.hpp"

// constructeurs :
// utiliser nullptr pour initialiser a NULL -> eauivalent de NULL en C
// mettre des : si tu veux initialiser des choses juste apres en appelant leurs constructeurs


PhoneBook::PhoneBook(void) : _nbContact(0)
{
	for (size_t i = 0; i < NB_CONTACT; i++)
		_contacts[i] = NULL;
}

// methodes :
void PhoneBook::addContact (Contact *newContact)
{
	_contacts[_nbContact] = newContact;
	_nbContact = (_nbContact + 1) % NB_CONTACT;
}

Contact *PhoneBook::getById (int index)
{
	return (_contacts[index]);
}