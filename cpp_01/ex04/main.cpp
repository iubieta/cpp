/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 19:56:53 by iubieta-          #+#    #+#             */
/*   Updated: 2025/08/04 20:40:49 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>


int main (int argc, char *argv[])
{
	if (argc < 4 || argc > 4) {
		std::cout << "Error: check your arguments\n";
		return (1);
	}

	std::ifstream file1(argv[1]);
	if (!file1) {
		std::cout << "Error while opening file\n";
		return (2);
	}

	std::ofstream file2(std::string(argv[1]) + ".replace");
	if (!file2) {
		std::cout << "Error while creating replace file\n";
		return (3);
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::string line;
	std::string newline;
	size_t index;
	while (std::getline(file1, line)) {
		std::cout << "line:" << line << "\n";
		index = line.find(s1);
		std::cout << "index:" << index << "\n";
		newline = "";
		while (line.find(s1) != std::string::npos) {
			newline.append(line.substr(0, index));
			newline.append(s2);
			line = line.substr(index + s1.length());
			std::cout << "line:" << line << "\n";
			index = line.find(s1);
			std::cout << "index:" << index << "\n";
		}
		newline.append(line.substr(0, index));
		newline.append("\n");
		std::cout << "newline:" << newline << "\n";
		file2 << newline;
	}
}
