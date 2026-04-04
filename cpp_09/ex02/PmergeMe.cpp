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
#include <ctime>
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
double PmergeMe::getListTime() const { return _listTime; }

// Methods --------------------------------------------------------------------

void	PmergeMe::sort() {
	std::clock_t	startTime = clock();
	GroupVec	groups;
	for (size_t i = 0; i < _original.size(); i++)
		groups.push_back(Group(1, _original[i]));
	fordJohnsonVec(groups);
	for (size_t i = 0; i < groups.size(); i++)
		_sortedVec.push_back(groups[i].back());
	std::clock_t	endTime = clock();
	_vecTime = static_cast<double>((endTime - startTime) * 1000000/ CLOCKS_PER_SEC);
}


// PRIVATE ====================================================================

// Utils ======================================================================
size_t PmergeMe::jacobsthal(size_t i) {
	static std::vector<size_t>	cache(2, 1);
	while (cache.size() <= i)
		cache.push_back(cache.back() + 2 * cache[cache.size() - 2]);
	return cache[i];
}

// Ford Johnson algorithm =====================================================

void	PmergeMe::fordJohnsonVec(GroupVec &groups) {
	// 0 - Return when only 1 group
	if (groups.size() < 2)
		return;

	// 1 - Swap group pairs if needed, in order to put the biggest last
	swapGroups(groups);
	// 1.1 - Extract the straggler if it is one
	Group	straggler = getStraggler(groups);

	// 2 - Fusion & recursion
	mergeGroups(groups);
	fordJohnsonVec(groups);

	// 3 - Insertion
	GroupVec winnerChain;
	GroupVec pendChain;
	GroupVec mainChain;
	// 3.1 - Split groups back
	splitGroups(groups, pendChain, winnerChain);
	// 3.2 - Insert winners and first pend in mainChain
	mainChain.insert(mainChain.end(), winnerChain.begin(), winnerChain.end());
	mainChain.insert(mainChain.begin(), pendChain[0]);
	// 3.3 - Insert in jacobsthal order
	jacobsthalInsertion(pendChain, winnerChain, mainChain);
	// 3.4 - Insert straggler if there is one
	insertStraggler(straggler, mainChain);
	
	groups = mainChain;
	return;
}

// Parts ----------------------------------------------------------------------

void	PmergeMe::swapGroups(GroupVec &groups) {
	for(size_t i = 0; i + 1 < groups.size(); i += 2) {
		if (groups[i].back() > groups [i+1].back())
			std::swap(groups[i], groups[i+1]);
	}
}

Group	PmergeMe::getStraggler(GroupVec &groups) {
	if (groups.size() % 2 > 0 && !groups.empty()) {
		return *(groups.end() - 1);
	}
	return Group();
}

void	PmergeMe::mergeGroups(GroupVec &groups) {
	GroupVec merged;
	for (size_t i = 0; i + 1 < groups.size(); i += 2) {
		Group fusion;
		fusion.insert(fusion.end(), groups[i].begin(), groups[i].end());
		fusion.insert(fusion.end(), groups[i + 1].begin(), groups[i + 1].end());
		merged.push_back(fusion);
	}
	groups = merged;
}

void	PmergeMe::splitGroups(GroupVec &groups, GroupVec &pendChain, GroupVec &winnerChain) {
	size_t mid = groups[0].size() / 2;
	for (size_t i = 0; i < groups.size(); ++i) {
		Group pend;
		pend.insert(pend.end(), groups[i].begin(), groups[i].begin() + mid);
		pendChain.push_back(pend);
		Group winner;
		winner.insert(winner.end(), groups[i].begin() + mid, groups[i].end());
		winnerChain.push_back(winner);
	}
}

void	PmergeMe::jacobsthalInsertion(GroupVec &pendChain, GroupVec &winnerChain, GroupVec &mainChain) {
	for (size_t i = 1; jacobsthal(i) < pendChain.size(); ++i) {
		size_t end = jacobsthal(i);
		size_t start = jacobsthal(i + 1) - 1;
		while (start > pendChain.size() - 1)
				--start;
		for (size_t j = start; j >= end; --j) {
			GroupVecIt first = mainChain.begin();
			GroupVecIt last = std::lower_bound(first, mainChain.end(), winnerChain[j], groupComparator);
			GroupVecIt pos = std::lower_bound(first, last, pendChain[j], groupComparator);
			mainChain.insert(pos, pendChain[j]);
		}
	}
}

void	PmergeMe::insertStraggler(Group &straggler, GroupVec &mainChain) {
	if (!straggler.empty()) {
		GroupVecIt first = mainChain.begin();
		GroupVecIt last = mainChain.end();
		GroupVecIt pos = std::lower_bound(first, last, straggler, groupComparator);
		mainChain.insert(pos, straggler);
	}
}

// NON MEMBER FUNCTIONS =======================================================


bool groupComparator(Group a, Group b) {
	return a.back() < b.back();
}

std::ostream &operator<<(std::ostream &os, const PmergeMe &obj) {
	os	<< "Sorting results:" << std::endl
		<< "  Input: " << obj.getInput() << std::endl
		<< "  Sorted Vector: " << obj.getSortedVec() << std::endl
		<< "  Sorting time: " << obj.getVecTime() << " uS" << std::endl 
		<< "  Sorted List: " << obj.getSortedList() << std::endl
		<< "  Sorting time: " << obj.getListTime() << " uS" << std::endl;
	return os;
}
