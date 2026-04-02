/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 20:29:22 by iubieta-          #+#    #+#             */
/*   Updated: 2026/04/02 01:20:35 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Utils.hpp"
#include <cstddef>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

// Class Construction =========================================================

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char **argv) {
	if (argc < 2)
		throw std::runtime_error("ERROR: No arguments given");
	for (int i = 1; i < argc; i++) {
		_original.push_back(parseInt(argv[i]));
	}
	_vecTime = 0;
	_listTime = 0;
}

PmergeMe::PmergeMe(const std::string &input) {
	std::istringstream in(input);
	int	value;
	while (in >> value) {
		if (value < 0) {
			std::ostringstream oss;
			oss << "ERROR: negative integer found => " << value;
			throw std::runtime_error(oss.str());
		}
		_original.push_back(value);
	}
	if (in.fail() && !in.eof())
		throw std::runtime_error("ERROR: invalid input found");
	if (in.bad())
		throw std::runtime_error("ERROR: something went wrong during the parsing");
	_vecTime = 0;
	_listTime = 0;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_original = other._original;
		_sortedVec = other._sortedVec;
		_sortedList = other._sortedList;
		_vecTime = other._vecTime;
		_listTime = other._listTime;
	}
	return *this;
}

PmergeMe::~PmergeMe() {};

// PUBLIC =====================================================================

// Getters --------------------------------------------------------------------

Group PmergeMe::getInput() const { return _original; }
Group PmergeMe::getSortedVec() const { return _sortedVec; }
Group PmergeMe::getSortedList() const { return _sortedList; }
double PmergeMe::getVecTime() const { return _vecTime; }
double PmergeMe::getListTime() const { return _vecTime; }

// Methods --------------------------------------------------------------------

void	PmergeMe::sort() {
	GroupVec	groups;
	for (size_t i = 0; i < _original.size(); i++)
		groups.push_back(Group(1, _original[i]));
	fordJohnsonVec(groups);
	for (size_t i = 0; i < groups.size(); i++)
		_sortedVec.push_back(groups[i].back());
}


// PRIVATE ====================================================================

// Utils ======================================================================


// Ford Johnson algorithm =====================================================

void	PmergeMe::fordJohnsonVec(GroupVec &groups) {
	// 0 - Return when only 1 group
	if (groups.size() < 2)
		return;

	// 1 - Swap group pairs if needed, in order to put the biggest last
	for(size_t i = 0; i + 1 < groups.size(); i += 2) {
		if (groups[i].back() > groups [i+1].back())
			std::swap(groups[i], groups[i+1]);
	}
	Group	straggler;
	if (groups.size() % 2 > 0 && !groups.empty()) {
		straggler = *(groups.end() - 1);
	}
	
	// 2 - Fusion & recursion
	GroupVec merged;
	for (size_t i = 0; i + 1 < groups.size(); i += 2) {
		Group fusion;
		fusion.insert(fusion.end(), groups[i].begin(), groups[i].end());
		fusion.insert(fusion.end(), groups[i + 1].begin(), groups[i + 1].end());
		merged.push_back(fusion);
	}
	fordJohnsonVec(merged);

	// 3 - Insertion
	// 3.1 - Split groups back
	GroupVec winnerChain;
	GroupVec pendChain;
	GroupVec mainChain;
	size_t mid = merged[0].size() / 2;
	for (size_t i = 0; i < merged.size(); ++i) {
		Group pend;
		pend.insert(pend.end(), merged[i].begin(), merged[i].begin() + mid);
		pendChain.push_back(pend);
		Group winner;
		winner.insert(winner.end(), merged[i].begin() + mid, merged[i].end());
		winnerChain.push_back(winner);
		mainChain.push_back(winner);
	}
	// 3.2 - Insert mains and first pend in sorted vec
	mainChain.insert(mainChain.begin(), pendChain[0]);
	// 3.3 - Insert in jacobsthal order
	for (size_t i = 0; jacobsthal(i+1) < pendChain.size(); i = jacobsthal(i + 1)) {
		for (size_t j = jacobsthal(i+1); j > i; --j) {
			GroupVecIt first = mainChain.begin();
			GroupVecIt last = std::lower_bound(first, mainChain.end(), winnerChain[j], groupComparator);
			GroupVecIt pos = std::lower_bound(first, last, pendChain[j], groupComparator);
			mainChain.insert(pos, pendChain[j]);
		}
	}

	// 3.4 - Insert straggler if there is one
	if (!straggler.empty()) {
		GroupVecIt first = mainChain.begin();
		GroupVecIt last = mainChain.end();
		GroupVecIt pos = std::lower_bound(first, last, straggler, groupComparator);
		mainChain.insert(pos, straggler);
	}
	
	groups = mainChain;
	return;
}

// NON MEMBER FUNCTIONS =======================================================

size_t jacobsthal(size_t i) {
	static std::vector<size_t>	cache(2, 1);
	while (cache.size() <= i)
		cache.push_back(cache.back() + 2 * cache[cache.size() - 2]);
	return cache[i];
}

bool groupComparator(Group a, Group b) {
	return a.back() < b.back();
}

std::ostream &operator<<(std::ostream &os, const PmergeMe &obj) {
	os	<< "Sorting results:" << std::endl
		<< "  Input: " << obj.getInput() << std::endl
		<< "  Sorted Vector: " << obj.getSortedVec() << std::endl
		<< "  Sorting time: " << obj.getVecTime() << std::endl
		<< "  Sorted List: " << obj.getSortedList() << std::endl
		<< "  Sorting time: " << obj.getListTime() << std::endl;
	return os;
}
