#pragma once
# include <iostream>
# include "Weapon.hpp"

typedef std::string str;

class HumanB {

	public :
		HumanB();
		HumanB(str name);
		~HumanB();
		void	attack(void);
		void	setWeapon(Weapon &type);

	private :
		str		_name;
		Weapon	*_type;

};
