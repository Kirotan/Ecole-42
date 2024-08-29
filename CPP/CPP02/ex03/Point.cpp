#include "Point.hpp"

//Constructeur et destructeur

Point::Point() : _x(0), _y(0){}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY()){}

Point::~Point () {}


// Getteur

const Fixed	&Point::getX(void) const {return this->_x;}
const Fixed	&Point::getY(void) const {return this->_y;}


// Surcharge d'operateur

Point	&Point::operator=(const Point &other) {

	(void)other;
	return *this;
}
