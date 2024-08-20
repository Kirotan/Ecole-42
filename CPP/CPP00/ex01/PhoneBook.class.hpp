#pragma once
# include "Contact.class.hpp"

typedef std::string str;

class PhoneBook {

	public :

	//Constructor and Destructor
		PhoneBook(void);
		~PhoneBook(void);

		void	addContact();
		void	searchContact();

	private :
		Contact	_contacts[8];
		int		_nbContacts;

		void	addFirstName();
		void	addLastName();
		void	addNickname();
		void	addNumberPhone();
		void	addDarkestSecret();
		void	displayColumn(int i);
		void	displayMiniContact(int i);
		void	displayContact(int i);
		void	set_str(str line);
};
