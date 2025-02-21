#pragma once

#include "Data.hpp"
typedef unsigned long int uintptr_t;

class Serializer {
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
