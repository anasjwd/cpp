#pragma once
#include <exception>
#include <algorithm>

class ElementNotFound : public std::exception {
	public:
		const char* what(void) const throw() {
			return "Element not Found";
		}
};

template <typename T>
typename T::iterator easyfind(T& arr, int toFind)
{
	typename T::iterator it = find(arr.begin(), arr.end(), toFind);
	if (it == arr.end())
		throw ElementNotFound();
	return it;
}
