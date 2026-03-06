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

// CHANONICAL FORM =============================================================

// CONSTRUCTORS
BtcExch::BtcExch() {};
BtcExch::BtcExch(const std::string &input_file) {
	loadCsv(input_file);
};
BtcExch::BtcExch(const BtcExch &other) : _hist_data(other._hist_data) {};

// COPY OPERATOR
BtcExch& BtcExch::operator=(const BtcExch &other) {
	if (this != &other)
		this->_hist_data = other._hist_data;
	return *this;
};

// DESTRUCTOR
BtcExch::~BtcExch() {};

// PUBLIC FUNCTIONS =========================================================

void	BtcExch::calc_price(const std::string &date, float n) const {
	const_floatmapiterator_t it = _hist_data.lower_bound(date);
	std::cout << it->first << " => " << n
		<< " = " << it->second * n
		<< std::endl;
}

// PRIVATE FUNCTIONS =========================================================

void	BtcExch::trim(std::string &str) const {
	size_t start = str.find_first_not_of(' ');
	size_t end = str.find_first_not_of(start, ' ');
	str = str.substr(start, end);
}

void	BtcExch::loadCsv(const std::string &input_file) {
	std::ifstream	input(input_file.c_str(), std::ifstream::in);
	std::string		line;
	floatpair_t		pair;
	
	std::getline(input, line);
	while (std::getline(input,line)) {
		try {
			trim(line);
			pair = parseCsvLine(line);
			this->_hist_data.insert(pair);
		} catch (std::runtime_error &e)  {
			std::cout << e.what();
		}
	}
}
	
BtcExch::floatpair_t BtcExch::parseCsvLine(const std::string &line) {
	std::string		key;
	std::string		value_str;
	float			value;
	
	size_t	index = line.find_first_of(',');
	key = line.substr(0, index);
	value_str = line.substr(index + 1);
	std::istringstream	val_ss(value_str);
	val_ss >> value;
	if (val_ss.fail() || !val_ss.eof())
		throw std::runtime_error("Invalid value: " + value_str);
	return floatpair_t(key, value);
}
