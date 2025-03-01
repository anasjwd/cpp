#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <exception>

class Span
{
	private:
		std::vector<int> arr;
		unsigned int maxCanStore;
		class StoreIsFull: std::exception {
			public:
				const char* what() const throw() {
					return "can't add it, store is full";
				}
		};
	public:
		Span(void);
		Span(unsigned int maxCanStore);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(void);
};

#endif

