#include "Weapon.hpp"

Weapon::Weapon(str type) : _type(type) {

}

Weapon::Weapon() {

}

Weapon::~Weapon() {

}

str const	Weapon::getType(void) {

	return (this->_type);
}

void	Weapon::setType(str type) {

	this->_type = type;
}
