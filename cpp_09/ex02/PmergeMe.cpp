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


void PmergeMe::splitGroups(jacobSthalIns_t &jsi) { 
	diff_t pairSize = jsi.groupSize * 2;
	const_vecIntIt inBegin = jsi.inVector.begin();
	const_vecIntIt inEnd = jsi.inVector.end();

	for (size_t i = 0; inBegin + i * pairSize < inEnd ; ++i) {
		// Insert pend group 
		const_vecIntIt pendStart = inBegin + i * pairSize;
		// If not complete group insert and break
		if (inEnd - pendStart < jsi.groupSize) {
			jsi.pends.insert(jsi.pends.end(), pendStart, inEnd);
			break;
		}
		jsi.pends.insert(jsi.pends.end(), pendStart, pendStart + jsi.groupSize);
		
		// Insert main group
		const_vecIntIt mainStart = inBegin + i * pairSize + jsi.groupSize;
		// If not a complete group insert into pends and break
		if (inEnd - mainStart < jsi.groupSize) {
			jsi.pends.insert(jsi.pends.end(), mainStart, inEnd); 
			break;
		}
		jsi.mains.insert(jsi.mains.end(), mainStart, mainStart + jsi.groupSize);
	}
}

void PmergeMe::adjustPositions(jacobSthalIns_t &jsi, const vecIntIt &pos) {
	size_t	offset = pos - jsi.mains.begin();
	for (size_t i = offset; i < jsi.positions.size(); i++)
		if (jsi.positions[i] >= offset)
			jsi.positions[i] += jsi.groupSize;
}

jacobSthalIns_t		PmergeMe::initJSStruct(const std::vector<int> &inVector, const diff_t &groupSize) {

	jacobSthalIns_t	jsi;

	jsi.inVector = inVector;
	jsi.groupSize = groupSize;
	jsi.groupNumber = inVector.size() / groupSize;

	// Start to split
	splitGroups(jsi);

	// Init positions array to keep track of main[k] positions
	for (size_t i = 0; i < jsi.mains.size() / groupSize; ++i) {
		jsi.positions.push_back(i * groupSize);
	}

	return jsi;
}

// Funtion to insert a complete group from pends vector to main vector
void	PmergeMe::insertIntoMain(jacobSthalIns_t &jsi, size_t group) {

	size_t start = (group - 1) * jsi.groupSize;
	size_t end = group * jsi.groupSize;

	vecIntIt startIt = jsi.pends.begin() + start;
	vecIntIt endIt = jsi.pends.begin() + end;

	vecIntIt lowerLimit = jsi.mains.begin();
	vecIntIt higherLimit;
	// Straggler case
	if (group > jsi.groupNumber / 2)
		higherLimit = jsi.mains.end();
	else
		higherLimit = jsi.mains.begin() + jsi.positions[group - 1];
	// TODO: Crear busqueda binaria que solo compare los representantes de cada grupo
	vecIntIt pos = std::lower_bound(lowerLimit, higherLimit, jsi.pends[end - 1]);
	adjustPositions(jsi, pos);
	jsi.mains.insert(pos, startIt, endIt);
}

void	PmergeMe::insertExcess(jacobSthalIns_t &jsi) {
	size_t	excess = jsi.pends.size() % jsi.groupSize;
	if (excess == 0)
		return;
	vecIntIt startIt = jsi.pends.end() - excess;
	vecIntIt endIt = jsi.pends.end();
	vecIntIt pos = jsi.mains.end();
	jsi.mains.insert(pos, startIt, endIt);
}

std::vector<int> PmergeMe::jacobsthalInsertion(const std::vector<int> &inVector, const diff_t &groupSize) {

	// Init JSStruct
	jacobSthalIns_t jsi = initJSStruct(inVector, groupSize);

	// Insert first pend
	insertIntoMain(jsi, 1);

	// Insert rest of pair pends in jacobsthal order
	for (size_t i = 1; jacobsthal(i) < jsi.groupNumber / 2; ++i) {
		for (size_t j = jacobsthal(i + 1); j > jacobsthal(i);  j--) {
			if (j <= jsi.groupNumber / 2)
				insertIntoMain(jsi, j);
		}
	}
	if (jsi.groupNumber > 2 && jsi.groupNumber % 2 > 0)
		insertIntoMain(jsi, jsi.groupNumber / 2 + 1);
	insertExcess(jsi);
	return jsi.mains;
}

size_t PmergeMe::jacobsthal(size_t i) {
	static std::vector<size_t>	cache(2, 1);
	while (cache.size() <= i)
		cache.push_back(cache.back() + 2 * cache[cache.size() - 2]);
	return cache[i];
}
