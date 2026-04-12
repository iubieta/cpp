/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:26:18 by iubieta-          #+#    #+#             */
/*   Updated: 2026/03/01 16:50:09 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "utils.hpp"


bool	isLeapYear(int year) {
	if (year % 400 == 0)
		return true;
	if (year % 100 == 0)
		return false;
	if (year % 4 == 0)
		return true;
	return false;
}

bool	isValidDate(std::string date_str) {
	if (date_str[4] != '-' || date_str[7] != '-')
		return false;

	time_t now = time(NULL);
	struct tm *t = localtime(&now);
	std::istringstream date(date_str);
	int	year, month, day;
	std::istringstream (date_str.substr(0,4)) >> year;
	std::istringstream (date_str.substr(5,7)) >> month;
	std::istringstream (date_str.substr(8,10)) >> day;
	if (year < 2009 || year > 1900 + t->tm_year)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	if (month == 2 && day > 28 && !(isLeapYear(year) && day < 30))
		return false;
	return true;
}

bool	isValidValue(float n) {
	if (n < 0 || n > 1000)
		return false;
	return true;
}

int main(int argc, char *argv[]) {
	BtcExch btc("data.csv");
	
	if (argc != 2) {
		std::cout << "ERROR: check your arguments\n";
		return 1;
	}
	std::ifstream	input(argv[1], std::ifstream::in);
	std::string		line;
	
	std::getline(input, line);
	while (std::getline(input,line)) {
		try {
			size_t	index = line.find("|");
			std::string date = line.substr(0, index);
			trim(date);
			if (!isValidDate(date)) {
				std::cout << date << " => Error: bad input date" << std::endl;
				continue;
			}
			float	n;
			std::istringstream (line.substr(index + 1)) >> n;
			if (!isValidValue(n)) {
				std::cout << date << " => Error: bad input value, enter a number between 0 and 1000\n";
				continue;
			}
			btc.calc_price(date, n);
		} catch (std::exception &e)  {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
