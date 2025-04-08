// faire un ifndef :
#ifndef CONTACT_HPP
# define CONTACT_HPP


// faire tout les includes normalement :
# include <string> 


// defnir ta class :
class Contact {
	// trier tout les attributs/methodes par public/private/protected
	private :
		// int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		// static void	printStr(std::string str);

	public :
		// methodes
		Contact();
		void		setFirstName(std::string firstName);
		void		setLastName(std::string lastName);
		void		setNickname(std::string nickname);
		void		setPhoneNumber(std::string phoneNumber);
		void		setDarkestSecret(std::string darkestSecret);
		void		displayCol(int index);
		void		displayAll(void);

};



#endif