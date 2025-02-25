#pragma once

template <typename T>
class Array {
	private:
		T* array;
		unsigned int arraySize;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array(void);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int size(void) const;
};

#include "Array.tpp"
