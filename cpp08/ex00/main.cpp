#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main(void)
{
	int arr[] = {1, 2, 3, 4};
	std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
	try {
		std::cout << *(easyfind(v, 5)) << std::endl;
	}
	catch (ElementNotFound& e)
	{
		std::cout << "not found\n";
	}
	try {
		std::cout << *(easyfind(v, 4)) << std::endl;
	}
	catch (ElementNotFound& e)
	{
		std::cout << "not found\n";
	}
	return 0;
}
