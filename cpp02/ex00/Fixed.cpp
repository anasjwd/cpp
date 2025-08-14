#include "Fixed.hpp"
#include <iostream>

const int Fixed::fractional_bits_value = 8;

Fixed::Fixed(void)
{
	value = 0;
	std::cout << "Default constructor called" << std::endl;
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
	return (value);
	std::cout << "getRawBits member function called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
	std::cout << "setRawBits member function called" << std::endl;
}
