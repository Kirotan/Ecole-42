#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {

	Point	a(3, 2);
	Point	b(11, 3);
	Point	c(7, 12);
	Point	p1(7, 5);
	Point	p2(11,8);
	Point	p3(5,7);

	// inside
	 if (bsp(a, b, c, p1) == false)
	 	std::cout << "Inside" << std::endl;

	//outside
	if (bsp(a, b, c, p2) == false)
	 	std::cout << "Outside" << std::endl;

	//on line
	if (bsp(a, b, c, p3) == false)
	 	std::cout << "On line" << std::endl;

	//on point
	if (bsp(a, b, c, b) == false)
	 	std::cout << "On point" << std::endl;

	return 0;
}
