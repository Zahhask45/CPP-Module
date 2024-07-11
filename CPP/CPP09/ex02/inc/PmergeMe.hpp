#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>
#include <cmath>

class PmergeMe
{
private:
	std::vector<int> vec;
	std::deque<int> deq;
public:
	PmergeMe();
	PmergeMe(const PmergeMe&);
	PmergeMe(char **arg);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &rhs);
	void parse(char **arg);
	void forVector();
	void forDeque();
	void isSorted();

	const std::vector<int> *getVec() const;
};

std::ostream &operator<<(std::ostream &os, const PmergeMe& sp);



#endif
