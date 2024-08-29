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
		Fixed	getX(void);
		void	setX(Fixed x);
		Fixed	getY(void);
		void	setY(Fixed y);

	// Surcharge d'operateur
		Point	&operator=(const Point &other);


	private :

		const Fixed	_x;
		const Fixed	_y;
};
