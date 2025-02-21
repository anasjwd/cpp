#include "Data.hpp"

Data::Data(void): value(0) {}

Data::~Data(void) {}

Data::Data(const Data& other): value(other.value) {}

Data& Data::operator=(const Data& other)
{
	if (this == &other)
		return *this;
	value = other.value;
	return *this;
}

int Data::getValue(void) const {
	return value;
}
