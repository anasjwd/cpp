#include "iter.hpp"
#include <iostream>

void my_toupper(char& c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

void print(const char& c)
{
	std::cout << c;
}

int main(void)
{
	char array[] = "heLlo";

	iter(array, 5, my_toupper);
	iter(array, 5, print);
	std::cout << std::endl;
	return 0;
}
