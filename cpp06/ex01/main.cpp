#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
	Data* ptr1 = new Data();
	Data* ptr2;
	uintptr_t raw;

	raw = Serializer::serialize(ptr1);
	ptr2 = Serializer::deserialize(raw);
	std::cout << "og ptr: " << ptr1 << " value: " << ptr1->getValue() << std::endl;
	std::cout << "ds ptr: " << ptr1 << " value: " << ptr2->getValue() << std::endl;
	delete ptr2;
	return 0;
}
