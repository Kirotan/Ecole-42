# pragma once
# include <iostream>

typedef std::string str;

class Zombie {

	public :
		Zombie();
		Zombie(str name);
		~Zombie();
		void	announce(void);
		void	setName(str name);

	private :
		str	_name;

};

Zombie* zombieHorde( int N, std::string name );
