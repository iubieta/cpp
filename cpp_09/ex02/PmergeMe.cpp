/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 20:29:22 by iubieta-          #+#    #+#             */
/*   Updated: 2026/03/09 00:10:52 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
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

PmergeMe::PmergeMe(const std::string &input) : _input(input) {
	std::istringstream in(input);
	int	value;
	while (in >> value) {
		if (value < 0) {
			std::ostringstream oss;
			oss << "ERROR: negative integer found => " << value;
			throw std::runtime_error(oss.str());
		}
		_inputVector.push_back(value);
		_inputList.push_back(value);
	}
	if (in.fail() && !in.eof())
		throw std::runtime_error("ERROR: invalid input found");
	if (in.bad())
		throw std::runtime_error("ERROR: something went wrong during the parsing");
	std::vector<int> auxVector = _inputVector;
	_sortedVector = vectorFordJohnson(auxVector, 1);
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	this->_input = other._input;
	this->_inputVector = other._inputVector;
	this->_inputList = other._inputList;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		this->_input = other._input;
		this->_inputVector = other._inputVector;
		this->_inputList = other._inputList;
	}
	return *this;
}

PmergeMe::~PmergeMe() {};

// Public methods =============================================================

std::string PmergeMe::getInput() const {
	return _input;
}

std::vector<int> PmergeMe::getInputVector() const {
	return _inputVector;
}

std::list<int> PmergeMe::getInputList() const {
	return _inputList;
}

std::vector<int> PmergeMe::getSortedVector() const {
	return _sortedVector;
}

std::list<int> PmergeMe::getSortedList() const {
	return _sortedList;
}

void PmergeMe::printSortedVector() const {
	for (const_vecIntIt it = _sortedVector.begin(); it != _sortedVector.end(); ++it) {
		if (it == _sortedVector.begin())
			std::cout << " [ ";
		std::cout << *it;
		if (it != _sortedVector.end() - 1)
			std::cout  << " , ";
	}
	std::cout << " ] ";
}

// Ford Johnson algorithm =====================================================
//
std::vector<int> PmergeMe::vectorFordJohnson(std::vector<int> &inVector, diff_t groupSize) {
	
	//1. Pairing and comparing
	for (vecIntIt i = inVector.begin(); inVector.end() - i >= groupSize * 2; i+=groupSize * 2) {
		if (*(i + groupSize - 1) > *(i + groupSize * 2 - 1))
			std::swap_ranges(i, i + groupSize, i + groupSize);
	}

	//2. Recursion
	if (inVector.end() - inVector.begin() > groupSize * 2)
		inVector = vectorFordJohnson(inVector, groupSize * 2);
	
	//3. Insercion
	std::vector<int> sortVector = jacobsthalInsertion(inVector, groupSize);
	return sortVector;
}


void PmergeMe::splitGroups(const std::vector<int> &inVector, std::vector<int> &mains, 
		std::vector<int> &pends, const diff_t &groupSize) {
	diff_t pairSize = groupSize * 2;
	const_vecIntIt inBegin = inVector.begin();
	const_vecIntIt inEnd = inVector.end();

	for (size_t i = 0; inBegin + i * groupSize < inEnd ; ++i) {
		// Insert pend group 
		const_vecIntIt pendStart = inBegin + i * pairSize;
		// If not complete group insert and break
		if (inEnd - pendStart < groupSize) {
			pends.insert(pends.end(), pendStart, inEnd);
			break;
		}
		pends.insert(pends.end(), pendStart, pendStart + groupSize);
		
		// Insert main group
		const_vecIntIt mainStart = inBegin + i * pairSize + groupSize;
		// If not a complete group insert into pends and break
		if (inEnd - mainStart < groupSize) {
			pends.insert(pends.end(), mainStart, inEnd); 
			break;
		}
		mains.insert(mains.end(), mainStart, mainStart + groupSize);
	}
}

void PmergeMe::adjustPositions(std::vector<size_t> &positions, const diff_t &groupSize, size_t insertPos) {
	for (size_t i = 0; i < positions.size(); ++i) {
		if (positions[i] >= insertPos)
			positions[i] += groupSize;
	}
}

std::vector<int> PmergeMe::jacobsthalInsertion(std::vector<int> &inVector, diff_t groupSize) {

	// Split into mains and pends
	
	// Check for at least 1 group
	diff_t pairSize = groupSize * 2;
	size_t groupNumber = inVector.size() / pairSize;
	if (groupNumber == 0)
		return inVector;

	std::vector<int> mains;
	std::vector<int> pends;

	// Start to split
	splitGroups(inVector, mains, pends, groupSize);

	// Init positions array to keep track of main[k] positions
	std::vector<size_t> positions;
	for (size_t i = 0; i < groupNumber; ++i) {
		positions.push_back(i * groupSize);
	}

	// Insert the first pend at begin
	if (pends.end() - pends.begin() >= groupSize) {
		mains.insert(mains.begin(), pends.begin(), pends.begin() + groupSize);
		adjustPositions(positions, groupSize, 0);
	}

	// Insert in jacobsthal order
	// TODO: rethink jacobsthal insertion loop
	for (size_t i = 1; i < groupNumber; i = jacobsthal(i + 2)) {
		for (size_t j = i; j < jacobsthal(i + 1); j--) {
			vecIntIt pos = std::lower_bound(mains.begin(), mains.begin() + positions[j], pends[j * groupSize]);
			mains.insert(pos, pends.begin() + j * groupSize, pends.begin() + (j + 1) * groupSize);
			adjustPositions(positions, groupSize, *pos);
		}
	}

	// Insert last pend
	if (pends.size() % groupSize > 0) {
		vecIntIt pos = std::lower_bound(mains.begin(), mains.end(), *(pends.end() - 1));
		mains.insert(pos, pends.begin() + groupNumber * groupSize, pends.end());
	}

	return inVector;
}

size_t PmergeMe::jacobsthal(size_t i) {
	static std::vector<size_t>	cache(2, 1);
	while (cache.size() <= i)
		cache.push_back(cache.back() + 2 * cache[cache.size() - 2]);
	return cache[i];
}
