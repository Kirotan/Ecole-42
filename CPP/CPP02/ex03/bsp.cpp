#include "Fixed.hpp"
#include "Point.hpp"
#include <cstdlib>
#include <cmath>

float	area(float x1, float y1, float x2, float y2, float x3, float y3) {
	return std::abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0f);
}

bool	isOnLine(float x1, float y1, float x2, float y2, float px, float py) {

	float	areaTri = area(x1, y1, x2, y2, px, py);
	return areaTri == 0.0f;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {

	float	ax = a.getX().toFloat();
	float	ay = a.getY().toFloat();
	float	bx = b.getX().toFloat();
	float	by = b.getY().toFloat();
	float	cx = c.getX().toFloat();
	float	cy = c.getY().toFloat();
	float	px = point.getX().toFloat();
	float	py = point.getY().toFloat();


	if ((px == ax && py == ay) ||
		(px == bx && py == by) ||
		(px == cx && py == cy))
		return true;

	if (isOnLine(ax, ay, bx, by, px, py) ||
		isOnLine(bx, by, cx, cy, px, py) ||
		isOnLine(cx, cy, ax, ay, px, py))
		return true;

	float	areaABC = area(ax, ay, bx, by, cx, cy);
	float	areaPAB = area(px, py, ax, ay, bx, by);
	float	areaPBC = area(px, py, bx, by, cx, cy);
	float	areaPCA = area(px, py, cx, cy, ax, ay);

	const float epsilon = 0.0001f;
	if (std::abs(areaABC - (areaPAB + areaPBC + areaPCA)) < epsilon)
		return false;

	return true;
}
