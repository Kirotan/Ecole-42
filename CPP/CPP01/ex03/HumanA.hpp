#pragma once
# include <iostream>
# include "Weapon.hpp"

typedef std::string str;

class HumanA{

	public :
		HumanA(str name, Weapon type);
		~HumanA();
		void	attack(void);

	private :
		str		_name;
		Weapon	_type;

};
