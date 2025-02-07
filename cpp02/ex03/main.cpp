#include <iostream>
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int	main(void)
{
	Point a(0, 0);
	Point b(1, 2);
	Point c(2, 0);
	Point p1(1, 2.1);
	Point p2(1, 1);
	Point p3 (-1, 0);

	if (bsp(a, b, c, p1) == true)
		std::cout << ">> P1 is inside" << std::endl;
	else
		std::cout << ">> P1 is outside" << std::endl;

	if (bsp(a, b, c, p2) == true)
		std::cout << ">> P2 is inside" << std::endl;
	else
		std::cout << ">> P2 is outside" << std::endl;

	if (bsp(a, b, c, p3) == true)
		std::cout << ">> P3 is inside" << std::endl;
	else
		std::cout << ">> P3 is outside" << std::endl;

	return 0;
}
