#include "Array.hpp"
#include <iostream>

int main(void)
{
	Array<int> arr(5);
	Array<int> arr1;
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i;
	arr[2] = 69;
	std::cout << "arr: ";
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		if (i != 0 && i != arr.size())
			std::cout << ", ";
		std::cout << arr[i];
	}
	std::cout << std::endl;
	arr1 = arr;
	std::cout << "arr1: ";
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		if (i != 0 && i != arr.size())
			std::cout << ", ";
		std::cout << arr[i];
	}
	std::cout << std::endl;
	return 0;
}
