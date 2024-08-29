#include "Point.hpp"

//Constructeur et destructeur

Point::Point() : _x(0), _y(0){}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) {}

Point::~Point () {}


// Getteur

Fixed	Point::getX(void){return this->_x;}
Fixed	Point::getY(void){return this->_y;}


// Surcharge d'operateur

Point	&Point::operator=(const Point &other) {

	(void)other;
	return *this;
}
