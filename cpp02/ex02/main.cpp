#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a(1.1f);
	Fixed b(2);
	Fixed c;

	std::cout << ">> a:" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << a << std::endl;
	std::cout << a.toFloat() << std::endl;
	std::cout << a.toInt() << std::endl;

	std::cout << ">> b:" << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << b << std::endl;
	std::cout << b.toFloat() << std::endl;
	std::cout << b.toInt() << std::endl;

	std::cout << ">> c:" << std::endl;
	c = Fixed(12.24f);
	std::cout << c.getRawBits() << std::endl;
	std::cout << c << std::endl;
	std::cout << c.toFloat() << std::endl;
	std::cout << c.toInt() << std::endl;

	std::cout << std::endl << ">> comaprisons:" << std::endl;
	std::cout << a << " > " << b << ": " << (a > b) << std::endl;
	std::cout << a << " < " << b << ": " << (a < b) << std::endl;
	std::cout << a << " <= " << b << ": " << (a <= b) << std::endl;
	std::cout << a << " >= " << b << ": " << (a >= b) << std::endl;
	std::cout << a << " == " << b << ": " << (a == b) << std::endl;
	std::cout << a << " != " << b << ": " << (a != b) << std::endl;

	Fixed d = c;
	std::cout << std::endl << ">> Increment/Decrement:" << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "d is: " << d << std::endl;
	++c;
	std::cout << "c is: " << c << std::endl;
	if (c > d)
		std::cout << "++c: c > d" << std::endl;
	else
		std::cout << "++c: failed" << std::endl;
	--c;
	if (c == d)
		std::cout << "--c: c == d" << std::endl;
	else
		std::cout << "--c: failed" << std::endl;
	c--;
	if (c <= d)
		std::cout << "c--: c <= d" << std::endl;
	else
		std::cout << "c--: failed" << std::endl;

	std::cout << std::endl << "Min/Max:" << std::endl;
	std::cout << "a: " << a << " c: " << c << std::endl;
	std::cout << "max: " << Fixed::max(a, c) << std::endl;
	std::cout << "min: " << Fixed::min(a, c) << std::endl;

	std::cout << std::endl << "Operations:" << std::endl;
	std::cout << a << " + " << b << " = " << (a + b) << std::endl;
	std::cout << a << " - " << b << " = " << (a - b) << std::endl;
	std::cout << a << " * " << b << " = " << (a * b) << std::endl;
	std::cout << a << " / " << b << " = " << (a / b) << std::endl;
	return 0;
}
