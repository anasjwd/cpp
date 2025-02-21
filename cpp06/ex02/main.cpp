#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

Base* generate(void)
{
	Base* ptr;
	int loto;

	srand(time(0));
	loto = rand() % 3;
	if (loto == 0)
		ptr = new A();
	else if (loto == 1)
		ptr = new B();
	else if (loto == 2)
		ptr = new C();
	return ptr;
}

void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if (a != NULL)
	{
		std::cout << "Derived class A" << std::endl;
		return ;
	}
	B* b = dynamic_cast<B*>(p);
	if (b != NULL)
	{
		std::cout << "Derived class B" << std::endl;
		return ;
	}
	C* c = dynamic_cast<C*>(p);
	if (c != NULL)
	{
		std::cout << "Derived class C" << std::endl;
		return ;
	}
	std::cout << "Derived class undefined" << std::endl;
}

void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Derived class A" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Derived class B" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Derived class C" << std::endl;
		return ;
	}
	catch (std::exception& e) {}
	std::cout << "Derived class undefined" << std::endl;
}

int main(void)
{
	Base* ptr;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
	return (0);
}
