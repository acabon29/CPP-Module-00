// faire un ifndef :
#ifndef PHONBOOK_HPP
# define PHONBOOK_HPP


// faire tout les includes normalement :
// # include <string> 
# include <./Contact.hpp> 

#define NB_CONTACT 8


// defnir ta class :
class PhoneBook {
	// trier tout els attributs/methodes par public/private/protected
	private :
		int		_nbContact;
		Contact	*_contacts[NB_CONTACT];

	public :
		// Il faut mettre le constructeur
		PhoneBook();
		void	addContact(Contact *newContact);
		Contact	*getById(int index);

};



#endif