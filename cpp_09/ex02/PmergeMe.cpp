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

// OLD CODE ===================================================================

// std::vector<int> PmergeMe::vectorFordJohnson(std::vector<int> &inVector, diff_t groupSize) {
// 	
// 	//1. Pairing and comparing
// 	for (vecIntIt i = inVector.begin(); inVector.end() - i >= groupSize * 2; i+=groupSize * 2) {
// 		if (*(i + groupSize - 1) > *(i + groupSize * 2 - 1))
// 			std::swap_ranges(i, i + groupSize, i + groupSize);
// 	}
//
// 	//2. Recursion
// 	if (inVector.end() - inVector.begin() > groupSize * 2)
// 		inVector = vectorFordJohnson(inVector, groupSize * 2);
// 	
// 	//3. Insercion
// 	std::vector<int> sortVector = jacobsthalInsertion(inVector, groupSize);
// 	return sortVector;
// }
//
//
// void PmergeMe::splitGroups(jacobSthalIns_t &jsi) { 
// 	diff_t pairSize = jsi.groupSize * 2;
// 	const_vecIntIt inBegin = jsi.inVector.begin();
// 	const_vecIntIt inEnd = jsi.inVector.end();
//
// 	for (size_t i = 0; inBegin + i * pairSize < inEnd ; ++i) {
// 		// Insert pend group 
// 		const_vecIntIt pendStart = inBegin + i * pairSize;
// 		// If not complete group insert and break
// 		if (inEnd - pendStart < jsi.groupSize) {
// 			jsi.pends.insert(jsi.pends.end(), pendStart, inEnd);
// 			break;
// 		}
// 		jsi.pends.insert(jsi.pends.end(), pendStart, pendStart + jsi.groupSize);
// 		
// 		// Insert main group
// 		const_vecIntIt mainStart = inBegin + i * pairSize + jsi.groupSize;
// 		// If not a complete group insert into pends and break
// 		if (inEnd - mainStart < jsi.groupSize) {
// 			jsi.pends.insert(jsi.pends.end(), mainStart, inEnd); 
// 			break;
// 		}
// 		jsi.mains.insert(jsi.mains.end(), mainStart, mainStart + jsi.groupSize);
// 	}
// }
//
// void PmergeMe::adjustPositions(jacobSthalIns_t &jsi, const vecIntIt &pos) {
// 	size_t	offset = pos - jsi.mains.begin();
// 	for (size_t i = offset; i < jsi.positions.size(); i++)
// 		if (jsi.positions[i] >= offset)
// 			jsi.positions[i] += jsi.groupSize;
// }
//
// jacobSthalIns_t		PmergeMe::initJSStruct(const std::vector<int> &inVector, const diff_t &groupSize) {
//
// 	jacobSthalIns_t	jsi;
//
// 	jsi.inVector = inVector;
// 	jsi.groupSize = groupSize;
// 	jsi.groupNumber = inVector.size() / groupSize;
//
// 	// Start to split
// 	splitGroups(jsi);
//
// 	// Init positions array to keep track of main[k] positions
// 	for (size_t i = 0; i < jsi.mains.size() / groupSize; ++i) {
// 		jsi.positions.push_back(i * groupSize);
// 	}
//
// 	return jsi;
// }
//
// // Binary search comparing only with group leader-elements
// vecIntIt	PmergeMe::groupLowerBound(jacobSthalIns_t &jsi, vecIntIt limit, int target) {
// 	vecIntIt low = jsi.mains.begin();
// 	vecIntIt high = limit;
// 	while (low < high) {
// 		vecIntIt	mid = low + ((high - low) / jsi.groupSize / 2) * jsi.groupSize;
// 		if (target < *mid)
// 			high = mid;
// 		else if (target >= *(mid + jsi.groupSize))
// 			low = mid + 1;
// 		else
// 			return mid;
// 	}
// 	return low;
// }
//
// // Funtion to insert a complete group from pends vector to main vector
// void	PmergeMe::insertIntoMain(jacobSthalIns_t &jsi, size_t group) {
//
// 	size_t start = (group - 1) * jsi.groupSize;
// 	size_t end = group * jsi.groupSize;
//
// 	vecIntIt startIt = jsi.pends.begin() + start;
// 	vecIntIt endIt = jsi.pends.begin() + end;
//
// 	vecIntIt lowerLimit = jsi.mains.begin();
// 	vecIntIt higherLimit;
// 	// Straggler case
// 	if (group > jsi.groupNumber / 2)
// 		higherLimit = jsi.mains.end();
// 	else
// 		higherLimit = jsi.mains.begin() + jsi.positions[group - 1];
// 	// TODO: Crear busqueda binaria que solo compare los representantes de cada grupo
// 	vecIntIt pos = std::lower_bound(lowerLimit, higherLimit, jsi.pends[end - 1]);
// 	adjustPositions(jsi, pos);
// 	jsi.mains.insert(pos, startIt, endIt);
// }
//
// void	PmergeMe::insertExcess(jacobSthalIns_t &jsi) {
// 	size_t	excess = jsi.pends.size() % jsi.groupSize;
// 	if (excess == 0)
// 		return;
// 	vecIntIt startIt = jsi.pends.end() - excess;
// 	vecIntIt endIt = jsi.pends.end();
// 	vecIntIt pos = jsi.mains.end();
// 	jsi.mains.insert(pos, startIt, endIt);
// }
//
// std::vector<int> PmergeMe::jacobsthalInsertion(const std::vector<int> &inVector, const diff_t &groupSize) {
//
// 	// Init JSStruct
// 	jacobSthalIns_t jsi = initJSStruct(inVector, groupSize);
//
// 	// Insert first pend
// 	insertIntoMain(jsi, 1);
//
// 	// Insert rest of pair pends in jacobsthal order
// 	for (size_t i = 1; jacobsthal(i) < jsi.groupNumber / 2; ++i) {
// 		for (size_t j = jacobsthal(i + 1); j > jacobsthal(i);  j--) {
// 			if (j <= jsi.groupNumber / 2)
// 				insertIntoMain(jsi, j);
// 		}
// 	}
// 	if (jsi.groupNumber > 2 && jsi.groupNumber % 2 > 0)
// 		insertIntoMain(jsi, jsi.groupNumber / 2 + 1);
// 	insertExcess(jsi);
// 	return jsi.mains;
// }
std::ostream &operator<<(std::ostream &os, const PmergeMe &obj) {
	os	<< "Sorting results:" << std::endl
		<< "  Input: " << obj.getInput() << std::endl
		<< "  Sorted Vector: " << obj.getSortedVec() << std::endl
		<< "  Sorting time: " << obj.getVecTime() << std::endl
		<< "  Sorted List: " << obj.getSortedList() << std::endl
		<< "  Sorting time: " << obj.getListTime() << std::endl;
	return os;
}
