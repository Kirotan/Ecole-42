# pragma once
# include <iostream>

typedef std::string str;

class Zombie {

	public :
		Zombie();
		Zombie(str name);
		~Zombie();
		void	announce( void );

	private :
		str	_name;

};

Zombie*	newZombie(str name);
void	randomChump(str name);
