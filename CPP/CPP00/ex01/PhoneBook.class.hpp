#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include "Contact.class.hpp"

typedef std::string str;

class PhoneBook {

	public :

	//Constructor and Destructor
		PhoneBook(void);
		~PhoneBook(void);

		void	addContact();
		void	addFirstName();
		void	addLastName();
		void	addNickname();
		void	addNumberPhone();

	private :
		Contact	_contacts[8];
		int		_nbContacts;
};
#endif
