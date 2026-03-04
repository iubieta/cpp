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
			std::string date = line.substr(0, line.find(" "));
			float	n;
			std::istringstream (line.substr(line.find(" ") + 1)) >> n;
			btc.calc_price(date, n);
		} catch (std::runtime_error &e)  {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
