#include "Fixed.hpp"

Fixed::Fixed() {

	_value = 0;
}

Fixed::Fixed(int const value) {

	setRawBits(value << _litt);
}

Fixed::Fixed(float const value) {

	setRawBits((int)roundf(value * (1 << _litt)));
}

Fixed::~Fixed() {

}

Fixed::Fixed	(const Fixed &other) {

	*this = other;
}

Fixed	&Fixed::operator=(const Fixed &other) {

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
