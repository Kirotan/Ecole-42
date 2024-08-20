#pragma once
# include <iostream>

typedef std::string str;

class Contact {
	public :

	//Constructor and Destructor
		Contact(void);
		~Contact(void);

	//Getters
		str	getFirstName(void);
		str	getLastName(void);
		str	getNickname(void);
		str	getPhoneNumber(void);
		str	getDarkestSecret(void);
		int	getIndex(void);

	//Setters
		void	setFirstName(str firstName);
		void	setLastName(str lastName);
		void	setNickname(str nickname);
		void	setPhoneNumber(str phoneNumber);
		void	setDarkestSecret(str darkestSecret);
		void	setIndex(int index);

	private :
		str	_firstName;
		str	_lastName;
		str	_nickname;
		str	_phoneNumber;
		str	_darkestSecret;
		int	_index;
};
