/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digoncal <digoncal@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/04/17 16:11:10 by digoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//============================ Constructors ==================================
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &value) {
	*this = value;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &value) {
	this->vec = value.vec;
	this->lst = value.lst;
	return *this;
}

PmergeMe::~PmergeMe() {}

// =========================== Print elements ==================================
template<typename Container>
void	printElements(const Container& con, const std::string& str) {
	std::cout << str << ": ";
	typename Container::const_iterator it;
	for(it = con.begin(); it != con.end(); it++) {
		std::cout << *it;
		typename Container::const_iterator tmp = it;
		++tmp;
		if (tmp != con.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

// =============================== JacobsThal ==================================
int jacobsthalGenerator(std::size_t nIdx) {
	static std::vector<int> mem; // Memoization to store Jacobsthal numbers
	if (mem.empty()) {
		mem.push_back(0); // J(0) = 0
		mem.push_back(1); // J(1) = 1
		mem.push_back(1); // J(2) = 1
	}

	while (mem.size() <= nIdx) {
		int nextVal = mem[mem.size() - 1] + 2 * mem[mem.size() - 2];
		mem.push_back(nextVal); // J(n) = J(n-1) * 2 + J(n-2)
	}

	return mem[nIdx];
}

template <typename Cont>
std::vector<int> jacobsthalSequence(const Cont& pend) {
	std::vector<int> jacobsthalSequence;
	std::size_t pendLen = pend.size();

	if (pendLen >= 3) {
		std::size_t jacobIdx = 3;
		int jacobValue = jacobsthalGenerator(jacobIdx);
		while (jacobValue < static_cast<int>(pendLen)) {
			jacobsthalSequence.push_back(jacobValue);
			++jacobIdx;
			jacobValue = jacobsthalGenerator(jacobIdx);
		}
	}

	return jacobsthalSequence;
}

// ================================= Utils =====================================
template <typename Cont>
std::vector<int> computeInsertionOrder(const Cont& pend) {
    std::vector<int> order;
    int p = static_cast<int>(pend.size());

    if (p <= 2) {
        for (int i = 0; i < p; ++i)
            order.push_back(i);
    } else {
        std::vector<int> jacobSeq = jacobsthalSequence(pend);
        int prev = -1;
        order.push_back(0);

        for (size_t j = 0; j < jacobSeq.size(); ++j) {
            int curr = jacobSeq[j];
            for (int i = curr; i > prev; --i) {
                if (i < p && i != 0)
                    order.push_back(i);
            }
            prev = curr;
        }

        for (int i = prev + 1; i < p; ++i) {
            if (std::find(order.begin(), order.end(), i) == order.end())
                order.push_back(i);
        }
    }

    return order;
}

template <typename PairCont, typename Cont>
Cont createPendCont(const PairCont& pairs, Cont& container) {
    container.clear();
    Cont pend;

    for (typename PairCont::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        // Use iterators to access elements instead of using pointer arithmetic
        typename PairCont::value_type pair = *it;
        
        if (pair.size() == 2) {
            container.push_back(pair.back()); // larger element
            pend.push_back(pair.front());     // smaller element (to insert later)
        } else {
            // Handle the last singleton if list is odd
            container.push_back(pair.front());
        }
    }

    return pend;
}

// ============================== Sort Pairs ===================================
template <typename Cont>
void mergeInsertPairs(Cont& cont, const Cont& pend) {
    std::vector<int> insertionOrder = computeInsertionOrder(pend);

    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        int idx = insertionOrder[i];
        if (idx < 0 || static_cast<size_t>(idx) >= pend.size())
            continue;

        typename Cont::const_iterator it = pend.begin();
        std::advance(it, idx);

        typename Cont::iterator pos = std::upper_bound(cont.begin(), cont.end(), *it);
        cont.insert(pos, *it);
    }
}

template <typename Cont>
void sortPairsByMax(Cont& pairs) {
    if (pairs.size() < 2)
        return;

    typename Cont::iterator it = ++pairs.begin(); // start at second element
    while (it != pairs.end()) {
        typename Cont::value_type key = *it;
        typename Cont::iterator j = it;
        typename Cont::iterator prev = j;
        --prev;

        while (j != pairs.begin() && *(--j) > key) {
            *(++j) = *j;
            --j;
        }
        *(++j) = key;
        ++it;
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
    if (vector.size() < 2) {return vector;}

	std::vector<std::vector<unsigned int> > pairs;
    
	createSortedPairs(vector, pairs);
    sortPairsByMax(pairs);
    mergeInsertPairs(vector, createPendCont(pairs, vector));

    return vector;
}


void	PmergeMe::sortVector(int ac) {
	printElements(vec, "Before");

	std::clock_t start = std::clock();
	std::vector<unsigned int> sorted = mergeInVector(vec);
	double time = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000;

	printElements(sorted, "After");
	std::cout << "Time to process a range of [" << ac - 1 << "] elements "
		<< "with std::vector<unsigned int> : " << time << " µs" << std::endl;
}

// ================================= Lists =====================================
std::list<unsigned int>	mergeInList(std::list<unsigned int>& list) {
	if (list.size() < 2) {return list;}
		
	std::list<std::list<unsigned int> > pairs;
	
    createSortedPairs(list, pairs);
    sortPairsByMax(pairs);
    mergeInsertPairs(list, createPendCont(pairs, list));

	return list;
}

void	PmergeMe::sortList(int ac) {
	std::clock_t start = std::clock();
	mergeInList(lst);
	double time = static_cast<double>(std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC) * 100000;
	
	std::cout << "Time to process a range of [" << ac - 1 << "] elements "
			  << "with std::list<unsigned int> : " << time << " µs" << std::endl;
}
