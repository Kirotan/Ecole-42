#include "HumanA.hpp"

HumanA::HumanA(str name, Weapon &type) : _name(name), _type(type) {

	return ;
}

HumanA::~HumanA() {

	return ;
}

void	HumanA::attack(void) {

	std::cout << this->_name << " attacks with their " << this->_type.getType() << std::endl;
	return ;
}
