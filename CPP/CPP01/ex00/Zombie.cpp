# include "Zombie.hpp"

Zombie::Zombie() {

}

Zombie::Zombie(str name) : _name(name) {

	std::cout << _name << " is born." << std::endl;
}

Zombie::~Zombie() {

	std::cout << this->_name << " is dead." << std::endl;
}

void	Zombie::announce(void) {

	std::cout << this->_name << ": " << " BraiiiiiiinnnzzzZ..." << std::endl;
}
