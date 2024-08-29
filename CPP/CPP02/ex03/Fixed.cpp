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

bool	Fixed::operator<(const Fixed &other) const{

	if (this->getRawBits() < other.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>(const Fixed &other) const{

	return (this->getRawBits() > other.getRawBits());

}

bool	Fixed::operator>=(const Fixed &other) const{

	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed &other) const{

	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed &other) const{

	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const{

	return (this->getRawBits() != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other) {

	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) {

		return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) {

		return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) {

		return Fixed(this->toFloat() / other.toFloat());

}

Fixed	Fixed::operator++(int) {

	Fixed	tmp;

	tmp = *this;
	operator++();
	return tmp;
}

Fixed	&Fixed::operator++(){

	this->_value++;
	return *this;
}

Fixed	Fixed::operator--(int){

	Fixed	tmp;

	tmp = *this;
	operator--();
	return tmp;
}

Fixed	&Fixed::operator--(){

	this->_value--;
	return *this;
}

Fixed		&Fixed::min(Fixed &a, Fixed &b) {

	if (a < b)
		return a;
	return b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {

	if (a < b)
		return a;
	return b;

}

Fixed		&Fixed::max(Fixed &a, Fixed &b) {

	if (a > b)
		return a;
	return b;

}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {

	if (a > b)
		return a;
	return b;

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
