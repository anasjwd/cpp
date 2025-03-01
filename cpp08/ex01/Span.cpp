#include "Span.hpp"

Span::Span(void): maxCanStore(maxCanStore)
{}

Span::Span(unsigned int maxCanStore): maxCanStore(maxCanStore)
{}

Span::Span(const Span& other)
{
	//TODO: fill this
	return ;
}

Span& Span::operator=(const Span& other)
{
	//TODO: fill this
	return (*this);
}

Span::~Span(void)
{
	return ;
}

void addNumber(int number)
{
	if (arr.size() > maxCanStore)
		throw StoreIsFull();
	arr.push_back(number);
}
