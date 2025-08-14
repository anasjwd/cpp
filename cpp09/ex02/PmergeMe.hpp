#pragma once
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <exception>
#include <unistd.h>
#include <cmath>
#include <climits>
#include <algorithm>

class PmergeMe {
	private:
		std::vector<unsigned int> numsVec;
		std::deque<unsigned int> numsDeque;
		PmergeMe(void);

	public:
		PmergeMe(char** av);
		~PmergeMe(void);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		void MergeInsertionSortVec(std::vector<unsigned int>& nums);
		void printVec(void);
		void MergeInsertionSortDeque(std::deque<unsigned int>& nums);
		void printDeque(void);
		class Error : public std::exception {
			public:
				const char* what() const throw();
		};
};
