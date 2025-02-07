#include "Point.hpp"
#define ORIENT int
#define CLOCKWISE 1
#define COLLINEAR 0
#define COUNTERCLOCKWISE -1

#include <iostream>

typedef struct s_vec2 {
	Fixed x;
	Fixed y;
} t_vec2;

ORIENT getTriangleOrientation(const Point& a, const Point& b, const Point& c)
{
	Fixed orientation, x1, y1, x2, y2, x3, y3;

	x1 = a.getX();
	y1 = a.getY();
	x2 = b.getX();
	y2 = b.getY();
	x3 = c.getX();
	y3 = c.getY();
	orientation = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
	if (orientation > 0)
		return COUNTERCLOCKWISE;
	else if (orientation < 0)
		return CLOCKWISE;
	else
		return COLLINEAR;
}

t_vec2 calcOuterOrth(const Point& p1, const Point& p2, ORIENT orient)
{
	t_vec2	dirVec, orthVec;

	dirVec.x = p2.getX() - p1.getX();
	dirVec.y = p2.getY() - p1.getY();
	if (orient == CLOCKWISE) // (-y, x)
	{
		orthVec.x = Fixed(-dirVec.y.toFloat());
		orthVec.y = dirVec.x;
	}
	else if (orient == COUNTERCLOCKWISE) // (y, -x)
	{
		orthVec.x = dirVec.y;
		orthVec.y = Fixed(-dirVec.x.toFloat());
	}
	return orthVec;
}

t_vec2 calcVec(const Point& P1, const Point& P2)
{
	t_vec2	vec;

	vec.x = P2.getX() - P1.getX();
	vec.y = P2.getY() - P1.getY();
	return vec;
}

Fixed dot(const t_vec2 vec1, const t_vec2 vec2)
{
	Fixed value;

	value = vec1.x * vec2.x + vec1.y * vec2.y;
	return (value);
}

bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	t_vec2	abOuterOrth, bcOuterOrth, caOuterOrth;
	t_vec2	pToa, pTob, pToc;
	ORIENT	orient;

	orient = getTriangleOrientation(a, b, c);
	abOuterOrth = calcOuterOrth(a, b, orient); //v1
	bcOuterOrth = calcOuterOrth(b, c, orient); //v2
	caOuterOrth = calcOuterOrth(c, a, orient); //v3
	pToa = calcVec(point, a); //v1'
	pTob = calcVec(point, b); //v2'
	pToc = calcVec(point, c); //v3'
	if (dot(abOuterOrth, pToa) <= 0)
		return false;
	else if (dot(bcOuterOrth, pTob) <= 0)
		return false;
	else if (dot(caOuterOrth, pToc) <= 0)
		return false;
	return true;
}
