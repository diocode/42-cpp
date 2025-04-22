/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/04/21 14:24:09 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//============================ Constructors ==================================
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	this->vec = other.vec;
	this->lst = other.lst;
	return *this;
}

PmergeMe::~PmergeMe() {}

// ================================ Utils ======================================
template<typename Container>
void	printElements(const Container& cont, const std::string& str) {
	std::cout << str << ": ";
	typename Container::const_iterator it;
	for (it = cont.begin(); it != cont.end(); ++it) {
		std::cout << *it;
		typename Container::const_iterator tmp = it;
		++tmp;
		if (tmp != cont.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

template <typename Iterator>
bool isSorted(Iterator begin, Iterator end) {
    if (begin == end)
        return true; 

    Iterator next = begin;
    ++next;
    while (next != end) {
        if (*next < *begin) {
            return false;
        }
        ++begin;
        ++next;
    }
    return true;
}

template <typename PairCont, typename Cont>
Cont createPendCont(const PairCont& pairs, Cont& cont) {
	cont.clear();
	Cont pend;

	typename PairCont::const_iterator it;
	for (it = pairs.begin(); it != pairs.end(); ++it) {
		if (it->size() == 2) {
			cont.push_back(it->back());
			pend.push_back(it->front());
		} else {
			cont.push_back(it->front());
		}
	}
	return pend;
}

// =============================== Jacobsthal ==================================
int jacobsthalGenerator(std::size_t nIdx) {
	static std::vector<int> mem;
	if (mem.empty()) {
		mem.push_back(0);
		mem.push_back(1);
		mem.push_back(1);
	}

	while (mem.size() <= nIdx) {
		int nextVal = mem[mem.size() - 1] + 2 * mem[mem.size() - 2];
		mem.push_back(nextVal);
	}
	return mem[nIdx];
}

template <typename Cont>
std::vector<int> jacobsthalSequence(const Cont& pend) {
	std::vector<int> sequence;
	std::size_t len = pend.size();

	if (len >= 3) {
		std::size_t idx = 3;
		int val = jacobsthalGenerator(idx);
		while (val < static_cast<int>(len)) {
			sequence.push_back(val);
			++idx;
			val = jacobsthalGenerator(idx);
		}
	}
	return sequence;
}

template <typename Cont>
std::vector<int> computeInsertionOrder(const Cont& pend) {
	std::vector<int> order;
	int size = static_cast<int>(pend.size());

	if (size <= 2) {
		for (int i = 0; i < size; ++i)
			order.push_back(i);
	} else {
		std::vector<int> jacob = jacobsthalSequence(pend);
		int prev = -1;
		order.push_back(0);

		for (std::size_t j = 0; j < jacob.size(); ++j) {
			int curr = jacob[j];
			for (int i = curr; i > prev; --i) {
				if (i < size && i != 0)
					order.push_back(i);
			}
			prev = curr;
		}
		for (int i = prev + 1; i < size; ++i) {
			if (std::find(order.begin(), order.end(), i) == order.end())
				order.push_back(i);
		}
	}
	return order;
}

// ================================== Pairs ====================================
template <typename T>
struct CompareByBack {
	bool operator()(const T& a, const T& b) const {
		return a.back() < b.back();
	}
};

template <typename Cont>
void mergeInsertPairs(Cont& cont, const Cont& pend) {
	std::vector<int> order = computeInsertionOrder(pend);

	for (std::size_t i = 0; i < order.size(); ++i) {
		int idx = order[i];
		if (idx < 0 || static_cast<std::size_t>(idx) >= pend.size())
			continue;

		typename Cont::const_iterator it = pend.begin();
		std::advance(it, idx);

		typename Cont::iterator pos = cont.begin();
		while (pos != cont.end() && *pos <= *it)
			++pos;

		cont.insert(pos, *it);
	}
}

template <typename Cont, typename PairCont>
void createSortedPairs(const Cont& input, PairCont& output) {
	output.clear();
	typename Cont::const_iterator it = input.begin();

	while (it != input.end()) {
		unsigned int first = *it++;
		if (it != input.end()) {
			unsigned int second = *it++;
			if (first > second)
				std::swap(first, second);
			typename PairCont::value_type pair;
			pair.push_back(first);
			pair.push_back(second);
			output.push_back(pair);
		} else {
			typename PairCont::value_type pair;
			pair.push_back(first);
			output.push_back(pair);
		}
	}
}

// ================================ Vector =====================================
std::vector<unsigned int> mergeInVector(std::vector<unsigned int>& vector) {
	if (vector.size() < 2) return vector;

	std::vector<std::vector<unsigned int> > pairs;
	createSortedPairs(vector, pairs);

	std::sort(pairs.begin(), pairs.end(), CompareByBack<std::vector<unsigned int> >());

	std::vector<unsigned int> sorted;
	std::vector<unsigned int> pend = createPendCont(pairs, sorted);

	mergeInsertPairs(sorted, pend);
	return sorted;
}

void PmergeMe::sortVector(int ac) {
	printElements(vec, "Before");

	std::clock_t start = std::clock();
	std::vector<unsigned int> sorted = mergeInVector(vec);
	double time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC * 100000;

	printElements(sorted, "After");

    if (!isSorted(sorted.begin(), sorted.end())) {
    	std::cout << "Error: Not sorted." << std::endl;
		return;
    }

	std::cout << "Time to process a range of [" << ac - 1 << "] elements "
	          << "with std::vector<unsigned int> : " << time << " µs" << std::endl;
}

// ================================= List ======================================
std::list<unsigned int> mergeInList(std::list<unsigned int>& list) {
	if (list.size() < 2) return list;

	std::list<std::list<unsigned int> > pairs;
	createSortedPairs(list, pairs);

	pairs.sort(CompareByBack<std::list<unsigned int> >());

	std::list<unsigned int> sorted;
	std::list<unsigned int> pend = createPendCont(pairs, sorted);

	mergeInsertPairs(sorted, pend);
	return sorted;
}

void PmergeMe::sortList(int ac) {
	std::clock_t start = std::clock();
	std::list<unsigned int> sorted = mergeInList(lst);
	double time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC * 100000;

    if (!isSorted(sorted.begin(), sorted.end())) {
        std::cout << "Error: Not sorted." << std::endl;
		return;
    }

	std::cout << "Time to process a range of [" << ac - 1 << "] elements "
	          << "with std::list<unsigned int> : " << time << " µs" << std::endl;
}
