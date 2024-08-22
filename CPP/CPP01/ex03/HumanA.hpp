#pragma once
# include "Weapon.hpp"
# include <iostream>

typedef std::string str;

class HumanA {

	public :
		HumanA(str name, Weapon &type);
		~HumanA();
		void	attack(void);


	private :
		str		_name;
		Weapon	&_type;

};
