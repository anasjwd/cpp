#include "Fixed.hpp"
#include <iostream>
#include <ostream>
#include <math.h>

const int Fixed::fractional_bits_value = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const int ivalue)
{
	std::cout << "Int constructor called" << std::endl;
	value = ivalue << fractional_bits_value;
}

Fixed::Fixed(const float fvalue)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(fvalue * (1 << fractional_bits_value));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = other.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw)
{
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

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

bool Fixed::operator>(const Fixed& ToCompareWith) const
{
	return (this->toFloat() > ToCompareWith.toFloat());
}

bool Fixed::operator<(const Fixed& ToCompareWith) const
{
	return (this->toFloat() < ToCompareWith.toFloat());
}

bool Fixed::operator>=(const Fixed& ToCompareWith) const
{
	return (this->toFloat() >= ToCompareWith.toFloat());
}

bool Fixed::operator<=(const Fixed& ToCompareWith) const
{
	return (this->toFloat() <= ToCompareWith.toFloat());
}

bool Fixed::operator==(const Fixed& ToCompareWith) const
{
	return (this->toFloat() == ToCompareWith.toFloat());
}

bool Fixed::operator!=(const Fixed& ToCompareWith) const
{
	return (this->toFloat() != ToCompareWith.toFloat());
}

Fixed Fixed::operator+(const Fixed& rightSide) const
{
	Fixed	res;

	res.setRawBits(this->value + rightSide.getRawBits());
	return res;
}

Fixed Fixed::operator-(const Fixed& rightSide) const
{
	Fixed	res;

	res.setRawBits(this->value - rightSide.getRawBits());
	return res;
}

Fixed Fixed::operator*(const Fixed& rightSide) const
{
	Fixed	res(this->toFloat() * rightSide.toFloat());

	return res;
}

Fixed Fixed::operator/(const Fixed& rightSide) const
{
	Fixed	res(this->toFloat() / rightSide.toFloat());

	return res;
}

Fixed& Fixed::operator++(void) //++value
{
	++value;
	return *this;
}

Fixed Fixed::operator++(int) //value++
{
	Fixed	temp = *this;
	++value;
	return temp;
}

Fixed& Fixed::operator--(void)
{
	--value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed	temp = *this;
	--value;
	return temp;
}

const Fixed&	Fixed::min(const Fixed& left, const Fixed& right)
{
	if (left < right)
		return left;
	else
		return right;
}

Fixed&	Fixed::min(Fixed& left, Fixed& right)
{
	if (left < right)
		return left;
	else
		return right;
}

const Fixed&	Fixed::max(const Fixed& left, const Fixed& right)
{
	if (left > right)
		return left;
	else
		return right;
}

Fixed&	Fixed::max(Fixed& left, Fixed& right)
{
	if (left > right)
		return left;
	else
		return right;
}
