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
#include <cstddef>
#include <iomanip>
#include <iostream>

struct Data {
	unsigned int	index;
	std::string		word;
};

int main() {

	std::cout << "==== INT ARRAY ============== " << std::endl;
	
	std::cout << "---- DEFAULT CONSTRUCTOR --------" << std::endl;
	Array<int>	ai;
	std::cout << "size: " << ai.size() << std::endl;
	try {
		std::cout << "index 0: " << ai[0] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	Array<int>	ai_5(5);
	std::cout << "---- SIZE 5 ARRAY --------" << std::endl;
	std::cout << "size: " << ai_5.size() << std::endl;
	std::cout << "Assigning values:" << std::endl;
	for (unsigned int i = 0; i < ai_5.size(); i++) {
		ai_5[i] = i;
		std::cout << "  index " << i << " : " << ai_5[i] << std::endl;
	}
	std::cout << std::endl;

	std::cout << "ACCES BOUNDS CHECK" << std::endl;
	try {
		std::cout << "index -1: " << ai_5[-1] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "index 0: " << ai_5[0] << std::endl;
		std::cout << "index 4: " << ai_5[4] << std::endl;
		std::cout << "index 5: " << ai_5[5] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	Array<int>	ai_0(0);
	std::cout << "---- SIZE 0 ARRAY --------" << std::endl;
	std::cout << "size: " << ai_0.size() << std::endl;
	try {
		std::cout << "index 0: " << ai_0[0] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "---- BIG ARRAY ---------" << std::endl;
	Array<int> ai_big(1000);
	std::cout << "size: " << ai_big.size() << std::endl;
	std::cout << "Assigning values:" << std::endl;
	for (unsigned int i = 0; i < ai_big.size(); i++) {
		ai_big[i] = i;
	}
	std::cout << std::endl;

	std::cout << "ACCES BOUNDS CHECK" << std::endl;
	try {
		std::cout << "index -1: " << ai_big[-1] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "index 0: " << ai_big[0] << std::endl;
		std::cout << "index 999: " << ai_big[999] << std::endl;
		std::cout << "index 1000: " << ai_big[1000] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "---- COPY CONSTRUCTOR --------" << std::endl;
	Array<int>	ai_cp(ai_5);
	std::cout << "size: " << ai_5.size() << std::endl;
	std::cout << "Printing values:" << std::endl;
	for (unsigned int i = 0; i < ai_5.size(); i++) {
		std::cout << "  index " << i << " : " << ai_cp[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "DEEP COPY CHECK :" << std::endl;
	std::cout << "Original array address: " << &ai_5 << std::endl;
	std::cout << "New copy array address: " << &ai_cp << std::endl;
	std::cout << "Assigning new values to the copy array:" << std::endl;
	int	col_width = 5;
	std::cout << std::left << "  "
		<< std::setw(col_width)	<< "i"
		<< std::setw(col_width) << "og" 
		<< std::setw(col_width) << "cp";
	std::cout << std::endl;
	std::cout << "----------------" << std::endl;
	for (unsigned int i = 0; i < ai_5.size(); i++) {
		ai_cp[i] = i + 5;
		std::cout << std::left << "  "
			<< std::setw(col_width)	<< i
			<< std::setw(col_width) << ai_5[i]
			<< std::setw(col_width) << ai_cp[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "---- COPY OPERATOR ---------" << std::endl;
	std::cout << "re-copying ai_5 in ai_cp" << std::endl;
	ai_cp = ai_5;
	std::cout << "Printing values:" << std::endl;
	std::cout << std::left << "  "
		<< std::setw(col_width)	<< "i"
		<< std::setw(col_width) << "og" 
		<< std::setw(col_width) << "cp";
	std::cout << std::endl;
	std::cout << "----------------" << std::endl;
	for (unsigned int i = 0; i < ai_5.size(); i++) {
		std::cout << std::left << "  "
			<< std::setw(col_width)	<< i
			<< std::setw(col_width) << ai_5[i]
			<< std::setw(col_width) << ai_cp[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "DEEP COPY CHECK :" << std::endl;
	std::cout << "Original array address: " << &ai_5 << std::endl;
	std::cout << "New copy array address: " << &ai_cp << std::endl;
	std::cout << "Assigning new values to the copy array:" << std::endl;
	std::cout << std::left << "  "
		<< std::setw(col_width)	<< "i"
		<< std::setw(col_width) << "og" 
		<< std::setw(col_width) << "cp";
	std::cout << std::endl;
	std::cout << "----------------" << std::endl;
	for (unsigned int i = 0; i < ai_5.size(); i++) {
		ai_cp[i] = i + 5;
		std::cout << std::left << "  "
			<< std::setw(col_width)	<< i
			<< std::setw(col_width) << ai_5[i]
			<< std::setw(col_width) << ai_cp[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "AUTOASIGN COPY CHECK :" << std::endl;
	std::cout << "Original array address: " << &ai_5 << std::endl;
	std::cout << "Copying ai_5 into ai_5" << std::endl;
	ai_5 = ai_5;
	std::cout << "New copy array address: " << &ai_5 << std::endl;
	std::cout << "Printing values:" << std::endl;
	for (unsigned int i = 0; i < ai_5.size(); i++) {
		std::cout << "  index " << i << " : " << ai_5[i] << std::endl;
	}
	std::cout << std::endl;
	

	std::cout << "---- CONST ARRAY ---------" << std::endl;
	const Array<int> ai_const = ai_5;
	std::cout << "size: " << ai_const.size() << std::endl;
	std::cout << "Printing values:" << std::endl;
	std::cout << std::left << "  "
		<< std::setw(col_width)	<< "i"
		<< std::setw(col_width) << "val";
	std::cout << std::endl;
	std::cout << "----------------" << std::endl;
	for (unsigned int i = 0; i < ai_5.size(); i++) {
		std::cout << std::left << "  "
			<< std::setw(col_width)	<< i
			<< std::setw(col_width) << ai_const[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
	// Imposible to modifie values: Uncommented doesnt compile
	// ai_const[0] = 100;


	std::cout << "==== CHAR ARRAY ============== " << std::endl;
	
	Array<char>	str(5);
	std::cout << "size: " << str.size() << std::endl;
	std::cout << "Assigning values:" << std::endl;
	for (unsigned int i = 0; i < str.size(); i++) {
		str[i] = i + 'a';
		std::cout << "  index " << i << " : " << str[i] << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "ACCES BOUNDS CHECK" << std::endl;
	try {
		std::cout << "index -1: " << str[-1] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "index 0: " << str[0] << std::endl;
		std::cout << "index 4: " << str[4] << std::endl;
		std::cout << "index 5: " << str[5] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "==== STRUCT ARRAY ============== " << std::endl;
	
	Array<Data> myData(5);
	std::string text = "Hello world, arrays are cool!";
	std::cout << "size: " << myData.size() << std::endl;
	std::cout << "Assigning values:" << std::endl;
	size_t start = 0;
	size_t i = 0;
	while (start < text.length())  {
		size_t end = text.find_first_of(" ", start);
		myData[i].index = start;
		myData[i].word = text.substr(start, end - start);
		std::cout 
			<< "  element " << i << " : "
			<< "index = " << myData[i].index
			<< ", word = " << myData[i].word
			<< std::endl;
		if (end == std::string::npos)
			break;
		start = end+1;
		i++;
	}
	std::cout << std::endl;
	
	std::cout << "ACCES BOUNDS CHECK" << std::endl;
	try {
		std::cout 
			<< "  element " << -1 << " : "
			<< "index = " << myData[-1].index
			<< ", word = " << myData[-1].word
			<< std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout 
			<< "  element " << 0 << " : "
			<< "index = " << myData[0 ].index
			<< ", word = " << myData[0 ].word
			<< std::endl;
		std::cout 
			<< "  element " << 4 << " : "
			<< "index = " << myData[4].index
			<< ", word = " << myData[4].word
			<< std::endl;
		std::cout 
			<< "  element " << -5 << " : "
			<< "index = " << myData[-5].index
			<< ", word = " << myData[-5].word
			<< std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
