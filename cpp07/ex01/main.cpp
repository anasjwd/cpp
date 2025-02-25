#include "iter.hpp"
#include <iostream>

void my_toupper(char& c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

int main(void)
{
	char array[] = "heLlo";

	iter(array, 5, my_toupper);
	std::cout << array << std::endl;
	return 0;
}
