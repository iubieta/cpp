/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:08:50 by iubieta-          #+#    #+#             */
/*   Updated: 2026/02/09 23:02:20 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main() {

	std::cout << "==== INT ARRAY ============== " << std::endl;
	std::cout << std::endl;
	
	Array<int>	ai;
	std::cout << "DEFAULT CONSTRUCTOR: " << std::endl;
	std::cout << "size: " << ai.size() << std::endl;
	try {
		std::cout << "index 0: " << ai[0] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	Array<int>	ai_5(5);
	std::cout << "CONSTRUCTOR WITH SIZE 5: " << std::endl;
	std::cout << "size: " << ai_5.size() << std::endl;
	try {
		std::cout << "index 0: " << ai_5[0] << std::endl;
		std::cout << "index 2: " << ai_5[2] << std::endl;
		std::cout << "index 5: " << ai_5[5] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Assigning values:" << std::endl;
	for (unsigned int i = 0; i < ai_5.size(); i++) {
		ai_5[i] = i;
		std::cout << "  index " << i << " : " << ai_5[i] << std::endl;
	}
	std::cout << std::endl;
	
	Array<int>	ai_cp(ai_5);
	std::cout << "COPY CONSTRUCTOR" << std::endl;
	std::cout << "size: " << ai_5.size() << std::endl;
	std::cout << "Printing values:" << std::endl;
	for (unsigned int i = 0; i < ai_5.size(); i++) {
		std::cout << "  index " << i << " : " << ai_cp[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "DEEP COPY CHECK" << std::endl;
	std::cout << "Original array address: " << &ai_5 << std::endl;
	std::cout << "New copy array address: " << &ai_cp << std::endl;
	std::cout << "Assigning values to the copy array:" << std::endl;
	for (unsigned int i = 0; i < ai_5.size(); i++) {
		ai_cp[i] = i + 5;
		std::cout << "  index " << i << " : " << ai_cp[i] << std::endl;
	}
	std::cout << "Printing values of the original array:" << std::endl;
	for (unsigned int i = 0; i < ai_5.size(); i++) {
		std::cout << "  index " << i << " : " << ai_5[i] << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "==== CHAR ARRAY ============== " << std::endl;
	std::cout << std::endl;
	
	Array<char>	str(5);
	std::cout << "CONSTRUCTOR WITH SIZE 5: " << std::endl;
	std::cout << "size: " << str.size() << std::endl;
	try {
		std::cout << "index 0: " << str[0] << std::endl;
		std::cout << "index 2: " << str[2] << std::endl;
		std::cout << "index 5: " << str[5] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "Assigning values:" << std::endl;
	for (unsigned int i = 0; i < str.size(); i++) {
		str[i] = i + 'a';
		std::cout << "  index " << i << " : " << str[i] << std::endl;
	}
	std::cout << std::endl;
}
