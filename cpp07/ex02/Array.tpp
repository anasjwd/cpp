#include "Array.hpp"
#include <stdexcept>
#include <cstdlib>
#include <string>

template <typename T>
Array<T>::Array(void)
{
	array = NULL;
	arraySize = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	array = new T[n];
	arraySize = n;
}

template <typename T>
Array<T>::~Array(void)
{
	if (arraySize > 0)
		delete[] array;
}

template <typename T>
Array<T>::Array(const Array& other)
{
	arraySize = other.arraySize;
	array = new T[arraySize];
	for (unsigned int i = 0; i < arraySize; i++)
		array[i] = other[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this == &other)
		return *this;
	if (arraySize > 0)
		delete[] array;
	arraySize = other.arraySize;
	array = new T[arraySize];
	for (unsigned int i = 0; i < arraySize; i++)
		array[i] = other[i];
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= arraySize)
		throw std::out_of_range("index is out of bounds.");
	return array[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= arraySize)
		throw std::out_of_range("index is out of bounds.");
	return array[index];
}

template <typename T>
unsigned int Array<T>::size(void) const 
{
	return arraySize;
}
