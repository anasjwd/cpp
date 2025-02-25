#pragma once

template <typename T>
void iter(T* array, unsigned int length, void (*func)(T&))
{
	for (unsigned int i = 0; i < length; i++)
		func(array[i]);
}
