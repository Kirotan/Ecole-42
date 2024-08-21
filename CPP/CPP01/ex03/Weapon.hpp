#pragma once
# include <iostream>

typedef std::string str;

class Weapon {

	public :
		Weapon();
		Weapon(str type);
		~Weapon();
		str const	getType(void);
		void		setType(str type);

	private :
		str	_type;

};
