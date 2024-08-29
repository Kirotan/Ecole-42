#include "Fixed.hpp"
#include "Point.hpp"

float	area(float x1, float y1, float x2, float y2, float x3, float y3) {
	return std::abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0f);
}

bool	isOnEdge(Point const a, Point const b, Point const c, Point const point) {

	if (point == a || point == b || point == c)
		return true;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {


}
