#include "PmergeMe.hpp"

static ssize_t toInt(std::string str) {
	std::stringstream ss(str);
	for (unsigned int i = 0; i < str.size(); i++) {
		if (str[i] < '0' || str[i] > '9')
			return ( -1 );
	}
	ssize_t num;
	ss >> num;
	if (ss.fail() || !ss.eof() || num > INT_MAX)
		return ( -1 );
	return ( num );
}

static unsigned int avSize(char** av)
{
	unsigned int size = 0;
	while (av[size] != NULL) ++size;
	return ( size );
}

PmergeMe::PmergeMe(char** av) {
	unsigned int size = avSize(av);
	ssize_t num;
	for (unsigned int i = 0; i < size; i++)
	{
		num = toInt(av[i]);
		if (num == -1)
			throw Error();
		numsVec.push_back(num);
		numsDeque.push_back(num);
	}
	std::cout << "Before: ";
	for (unsigned int i = 0; i < numsVec.size(); i++)
		std::cout << numsVec[i] << " ";
	std::cout << std::endl;
	clock_t VecStart = clock();
	MergeInsertionSortVec(numsVec);
	clock_t VecEnd = clock();
	double timeForVec = static_cast<double>(VecEnd - VecStart) / CLOCKS_PER_SEC * 1000;

	clock_t DequeStart = clock();
	MergeInsertionSortDeque(numsDeque);
	clock_t DequeEnd = clock();
	double timeForDeque = static_cast<double>(DequeEnd - DequeStart) / CLOCKS_PER_SEC * 1000;

	std::cout << "After: ";
	for (unsigned int i = 0; i < numsVec.size(); i++)
		std::cout << numsVec[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << numsVec.size()
		<< "  elements with std::vector : " << timeForVec << "us\n";
	std::cout << "Time to process a range of " << numsVec.size()
		<< "  elements with std::Deque : " << timeForDeque << "us\n";
}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& other) {
	numsVec = other.numsVec;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other)
		return ( *this );
	numsVec = other.numsVec;
	return ( *this );
}

template <class Container>
static void sortPairs(Container& nums)
{
	for (unsigned int i = 0; i < nums.size(); i = i + 2)
	{
		if (i + 1 < nums.size() && nums[i] < nums[i + 1])
			std::swap(nums[i], nums[i + 1]);
	}
}

static unsigned int Jacobsthal(unsigned int idx) {
	if (idx == 0) return ( 1 );
	return ( (std::pow(2, idx) - std::pow(-1, idx)) / 3 );
}

template <class Container>
static void FormGroups(Container& a,
		Container& b, const Container& nums)
{
	unsigned int i = 0;
	while (i < nums.size()) {
		a.push_back(nums[i++]);
		if (i < nums.size())
			b.push_back(nums[i++]);
	}
}

template <class Container>
Container calcInsertionOrder(unsigned int size) {
	Container order;
	std::vector<bool> used(size, false);
	unsigned int idx;
	int js = 2;
	while (order.size() < size) {
		idx = Jacobsthal(js) - 1;
		while (idx >= size || used[idx] == true) {
			idx = (idx >= size) ? size - 1 : idx + 1;
			if (idx >= size) {
				idx = 0;
				while (idx < size && used[idx] == true)
					++idx;
			}
		}
		used[idx] = true;
		order.push_back(idx);
		++js;
	}
	return ( order );
}

template <class Container>
static void BinaryInsertion(Container& vec, unsigned int toAdd) {
	int left = 0, right = vec.size() - 1;
	unsigned int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (toAdd > vec[mid]) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}
	vec.insert(vec.begin() + left, toAdd);
}

template <class Container>
static void insertPairOfFirstElm(Container& nums,
		Container& groupA,
		Container& groupB) {
	unsigned int lookFor;
	unsigned int pair;
	lookFor = groupA[0];
	for (unsigned int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == lookFor)
		{
			if (i + 1 >= nums.size())
				return ;
			pair = nums[i + 1];
			break;
		}
	}
	groupA.insert(groupA.begin(), pair);
	groupB.erase(find(groupB.begin(), groupB.end(), pair));
}

void PmergeMe::MergeInsertionSortVec(std::vector<unsigned int>& nums) {
	if (nums.size() <= 1){
		return;
	}
	sortPairs<std::vector<unsigned int> >(nums); // [15, 4, 12, 18, 9] => [15, 4, 18, 12, 9]

	std::vector<unsigned int> groupA;
	std::vector<unsigned int> groupB;
	FormGroups<std::vector<unsigned int> >(groupA, groupB, nums); // A: [15, 18, 9] | B: [4, 12]

	MergeInsertionSortVec(groupA); // A: [9, 15, 18]

	insertPairOfFirstElm<std::vector<unsigned int> >(nums, groupA, groupB);

	std::vector<unsigned int> insertionOrder = calcInsertionOrder<std::vector<unsigned int> >(groupB.size());

	unsigned int toInsert;
	for (unsigned int i = 0; i < groupB.size(); i++) {
		toInsert = insertionOrder[i];
		BinaryInsertion<std::vector<unsigned int> >(groupA, groupB[toInsert]);
	}
	nums = groupA;
}

void PmergeMe::MergeInsertionSortDeque(std::deque<unsigned int>& nums) {
	if (nums.size() <= 1)
		return;
	sortPairs<std::deque<unsigned int> >(nums);

	std::deque<unsigned int> groupA;
	std::deque<unsigned int> groupB;
	FormGroups<std::deque<unsigned int> >(groupA, groupB, nums);

	MergeInsertionSortDeque(groupA);

	insertPairOfFirstElm<std::deque<unsigned int> >(nums, groupA, groupB);

	std::deque<unsigned int> insertionOrder = calcInsertionOrder<std::deque<unsigned int> >(groupB.size());

	unsigned int toInsert;
	for (unsigned int i = 0; i < groupB.size(); i++) {
		toInsert = insertionOrder[i];
		BinaryInsertion<std::deque<unsigned int> >(groupA, groupB[toInsert]);
	}
	nums = groupA;
}

void PmergeMe::printVec(void) {
	std::cout << "Vector: ";
	for (unsigned int i = 0; i < numsVec.size(); i++) {
		std::cout << numsVec[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque(void) {
	std::cout << "Deque: ";
	for (unsigned int i = 0; i < numsDeque.size(); i++) {
		std::cout << numsDeque[i] << " ";
	}
	std::cout << std::endl;
}

const char* PmergeMe::Error::what() const throw() {
	return ( "Error" );
}
