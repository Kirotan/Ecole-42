#include "Fixed.hpp"

Fixed::Fixed() {

	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(int const value) {

	std::cout << "Int constructor called" << std::endl;
	setRawBits(value << _litt);
}

Fixed::Fixed(float const value) {

	std::cout << "Float constructor called" << std::endl;
	setRawBits((int)roundf(value * (1 << _litt)));
}

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed	(const Fixed &other) {

	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other) {

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		setRawBits(other.getRawBits());
	return (*this);
}

std::ostream	&operator<<(std::ostream &out, const Fixed &other) {

	out << other.toFloat();
	return (out);
}

int Fixed::getRawBits( void ) const {

	return (this->_value);
}

void	Fixed::setRawBits( int const raw ) {

	(*this)._value = raw;
}

float	Fixed::toFloat(void) const {

	return ((float)getRawBits() / (1 << _litt));
}

int	Fixed::toInt(void) const {

	return (getRawBits() >> _litt);
}
