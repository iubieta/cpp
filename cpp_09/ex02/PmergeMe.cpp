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
	GroupVec	groups;
	for (size_t i = 0; i < _original.size(); i++)
		groups.push_back(Group(1, _original[i]));
	std::clock_t	startTime = clock();
	fordJohnsonVec(groups);
	for (size_t i = 0; i < groups.size(); i++)
		_sortedVec.push_back(groups[i].back());
	std::clock_t	endTime = clock();
	_vecTime = static_cast<double>((endTime - startTime) * 1000000/ CLOCKS_PER_SEC);

	LGroupList	lgroups;
	for (size_t i = 0; i < _original.size(); i++) {
		LGroup lgroup;
		lgroup.push_back(_original[i]);
		lgroups.push_back(lgroup);
	}
	startTime = clock();
	fordJohnsonList(lgroups);
	for (LGroupListIt it = lgroups.begin(); it != lgroups.end(); ++it) {
		_sortedList.insert(_sortedList.end(), it->begin(), it->end());
	}
	endTime = clock();
	_listTime = static_cast<double>((endTime - startTime) * 1000000/ CLOCKS_PER_SEC);
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

// Vector implementation ------------------------------------------------------

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

// Vector implementation parts ------------------------------------------------

void	PmergeMe::swapGroups(GroupVec &groups) {
	for(size_t i = 0; i + 1 < groups.size(); i += 2) {
		if (groups[i].back() > groups [i+1].back())
			std::swap(groups[i], groups[i+1]);
	}
}

Group	PmergeMe::getStraggler(GroupVec &groups) {
	if (groups.size() % 2 > 0 && !groups.empty()) {
		return groups.back();
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

// List implementation --------------------------------------------------------

void	PmergeMe::fordJohnsonList(LGroupList &groups) {
	// 0 - Return when only 1 group
	if (groups.size() < 2)
		return;

	// 1 - Swap group pairs if needed, in order to put the biggest last
	swapGroups(groups);
	// 1.1 - Extract the straggler if it is one
	LGroup	straggler = getStraggler(groups);

	// 2 - Fusion & recursion
	mergeGroups(groups);
	fordJohnsonList(groups);

	// 3 - Insertion
	LGroupList winnerChain;
	LGroupList pendChain;
	LGroupList mainChain;
	// 3.1 - Split groups back
	splitGroups(groups, pendChain, winnerChain);
	// 3.2 - Insert winners and first pend in mainChain
	mainChain.insert(mainChain.end(), winnerChain.begin(), winnerChain.end());
	mainChain.insert(mainChain.begin(), pendChain.front());
	// 3.3 - Insert in jacobsthal order
	jacobsthalInsertion(pendChain, winnerChain, mainChain);
	// 3.4 - Insert straggler if there is one
	insertStraggler(straggler, mainChain);
	
	groups = mainChain;
	return;
}

// List implementation parts --------------------------------------------------

void    PmergeMe::swapGroups(LGroupList &groups) {
	for(size_t i = 0; i + 1 < groups.size(); i += 2) {
		LGroupListIt a = groups.begin();
		LGroupListIt b = groups.begin();
		std::advance(a, i);
		std::advance(b, i + 1);
		if (a->back() > b->back())
			std::swap(*a, *b);
	}
}

LGroup	PmergeMe::getStraggler(LGroupList &groups) {
	if (groups.size() % 2 > 0 && !groups.empty()) {
		return groups.back();
	}
	return LGroup();
}

void	PmergeMe::mergeGroups(LGroupList &groups) {
	LGroupList merged;
	for (size_t i = 0; i + 1 < groups.size(); i += 2) {
		LGroup fusion;
		LGroupListIt a = groups.begin();
		LGroupListIt b = groups.begin();
		std::advance(a, i);
		std::advance(b, i + 1);
		fusion.insert(fusion.end(), a->begin(), a->end());
		fusion.insert(fusion.end(), b->begin(), b->end());
		merged.push_back(fusion);
	}
	groups = merged;
}

void	PmergeMe::splitGroups(LGroupList &groups, LGroupList &pendChain, LGroupList &winnerChain) {
	size_t mid = groups.front().size() / 2;
	for (size_t i = 0; i < groups.size(); ++i) {
		LGroupListIt a = groups.begin();
		std::advance(a, i);
		LGroup		pend;
		LGroupIt	start = a->begin();
		LGroupIt	end = a->begin();
		std::advance(end, mid);
		pend.insert(pend.end(), start, end);
		pendChain.push_back(pend);
		LGroup winner;
		std::advance(start, mid);
		std::advance(end, mid);
		winner.insert(winner.end(), start, end);
		winnerChain.push_back(winner);
	}
}

void	PmergeMe::jacobsthalInsertion(LGroupList &pendChain, LGroupList &winnerChain, LGroupList &mainChain) {
	for (size_t i = 1; jacobsthal(i) < pendChain.size(); ++i) {
		size_t end = jacobsthal(i);
		size_t start = jacobsthal(i + 1) - 1;
		while (start > pendChain.size() - 1)
				--start;
		for (size_t j = start; j >= end; --j) {
			LGroupListIt	pend = pendChain.begin();
			std::advance(pend, j);
			LGroupListIt	winner = winnerChain.begin();
			std::advance(winner, j);
			LGroupListIt	first = mainChain.begin();
			LGroupListIt	last = std::lower_bound(first, mainChain.end(), *winner, lgroupComparator);
			LGroupListIt	pos = std::lower_bound(first, last, *pend, lgroupComparator);
			mainChain.insert(pos, *pend);
		}
	}
}

void	PmergeMe::insertStraggler(LGroup &straggler, LGroupList &mainChain) {
	if (!straggler.empty()) {
		LGroupListIt first = mainChain.begin();
		LGroupListIt last = mainChain.end();
		LGroupListIt pos = std::lower_bound(first, last, straggler, lgroupComparator);
		mainChain.insert(pos, straggler);
	}
}

// NON MEMBER FUNCTIONS =======================================================

bool groupComparator(Group a, Group b) {
	return a.back() < b.back();
}

bool lgroupComparator(LGroup a, LGroup b) {
	return a.back() < b.back();
}

std::ostream &operator<<(std::ostream &os, const PmergeMe &obj) {
	os	<< "Sorting results:" << std::endl;
	if (obj.getInput().size() < 100)
		os << "  Input: " << obj.getInput() << std::endl;
	if (obj.getSortedVec().size() < 100)
		os << "  Sorted Vector: " << obj.getSortedVec() << std::endl;
	os << "  Sorting time: " << obj.getVecTime() << " uS" << std::endl;
	if (obj.getSortedList().size() < 100)
		os << "  Sorted List: " << obj.getSortedList() << std::endl;
	os << "  Sorting time: " << obj.getListTime() << " uS" << std::endl;
	return os;
}
