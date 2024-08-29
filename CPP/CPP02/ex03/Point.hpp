#pragma once
#include "Fixed.hpp"

class Point {

	public :

	// Constructeur et destructeur
		Point();
		Point(const Point &other);
		Point(const float x, const float y);
		~Point();

	//Getteur et setteur
		const Fixed	&getX(void) const;
		const Fixed	&getY(void) const;

	// Surcharge d'operateur
		Point	&operator=(const Point &other);


	private :

		const Fixed	_x;
		const Fixed	_y;
};
