#include "Fixed.hpp"
#include <iostream>
#include <ostream>
#include <cmath>
#include <iomanip>

const int Fixed::fractional_bits_value = 8;

Fixed::Fixed(void)
{
	value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int ivalue)
{
	value = ivalue << fractional_bits_value;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fvalue)
{
	value = roundf(fvalue * (1 << fractional_bits_value));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	value = other.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this == &other)
		return *this;
	value = other.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)value / (1 << fractional_bits_value));
}

int Fixed::toInt(void) const
{
	return (value >> fractional_bits_value);
}

std::ostream& operator<<(std::ostream& out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
