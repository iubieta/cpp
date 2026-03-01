/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 15:03:30 by iubieta-          #+#    #+#             */
/*   Updated: 2026/03/01 17:26:24 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstddef>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <string>

// CHANONICAL FORM =============================================================

// CONSTRUCTORS
BtcExch::BtcExch() {};
BtcExch::BtcExch(std::string input_file) {
	_loadCsv(input_file);
};
BtcExch::BtcExch(BtcExch &other) : _hist_data(other._hist_data) {};

// COPY OPERATOR
BtcExch& BtcExch::operator=(BtcExch &other) {
	if (this != &other)
		this->_hist_data = other._hist_data;
	return *this;
};

// DESTRUCTOR
BtcExch::~BtcExch() {};

// PRIVATE FUNCTIONS =========================================================

std::string	BtcExch::_trim(std::string str) {
	size_t start = str.find_first_not_of(' ');
	size_t end = str.find_first_not_of(start, ' ');
	return str.substr(start, end);
}

void	BtcExch::_loadCsv(std::string input_file) {
	std::ifstream	input(input_file.c_str(), std::ifstream::in);
	std::string		line;
	floatPair		pair;
	
	std::getline(input, line);
	while (std::getline(input,line)) {
		std::cout << "line: " << line;
		try {
			pair = _parseCsvLine(line);
			this->_hist_data.insert(pair);
		} catch (std::runtime_error &e)  {
			std::cout << e.what();
		}
		floatMap::iterator it = --_hist_data.end();
		std::cout << it->first << ", " << it->second << "\n";
	}
}
	
BtcExch::floatPair BtcExch::_parseCsvLine(std::string &line) {
	std::string		key;
	std::string		value_str;
	float			value;
	
	line = _trim(line);
	
	size_t			index = line.find_first_of(',');
	key = line.substr(0, index);
	value_str = line.substr(index + 1);
	std::istringstream	val_ss(value_str);
	val_ss >> value;
	if (val_ss.fail() || !val_ss.eof())
		throw std::runtime_error("Invalid value: " + value_str);
	return floatPair(key, value);
}

void	BtcExch::printDateValue(std::string date) {
	std::cout << _hist_data.at(date);
}
