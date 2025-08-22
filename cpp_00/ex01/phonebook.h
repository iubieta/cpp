/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:39:41 by iubieta-          #+#    #+#             */
/*   Updated: 2025/08/22 14:37:42 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <bits/types/wint_t.h>
#include <iomanip>
#include <ios>
#include <iostream>
#include <cctype>
#include <string>

#include "contact.h"

inline std::string truncate(const std::string &str, int width) {
	if (str.length() > (size_t)width)
		return (str.substr(0, width - 1) + ".");
	return str;
}

class PhoneBook {

	private:

		Contact list[8];
		int	size;
		
	public:
	
		// PhoneBook();
		// void setContact();
		// void getContact(int i)

	PhoneBook() {
		size = 0;
	};
		
	void addContact() {
		
		int i;
		std::string	input;

		if (size == 8)
			i = 0;
		else {
			i = size;
			size++;
		}
		
		std::cout << "  First name: ";
		std::cin >> input;
		list[i].set_first_name(input);

		std::cout << "  Last name: ";
		std::cin >> input;
		list[i].set_last_name(input);
		
		std::cout << "  Nickname: ";
		std::cin >> input;
		list[i].set_nickname(input);

		std::cout << "  Phone number: ";
		std::cin >> input;
		list[i].set_number(input);

		std::cout << "\n";
	}

	void print_contact(int i) {
	
		std::cout 
			<< "  First name: " << list[i].get_first_name() << "\n"
			<< "  Last name: " << list[i].get_last_name() << "\n"
			<< "  Nickname: " << list[i].get_nickname() << "\n"
			<< "  Phone number: " << list[i].get_number() << "\n"
			<< "\n";
	}

	void search_contact() {
		int col_width = 10;		
		std::cout 
			<< std::left
			<< std::setw(col_width) << "Index"
			<< "| " << std::setw(col_width) << "First name"
			<< "| " << std::setw(col_width) << "Last name"
			<< "| " << std::setw(col_width) << "Nickname"
			<< "\n";
	
		for (int i=0; i<size; i++) {
			std::cout	
				<< std::setw(col_width) << i + 1
				<< "| " << std::setw(col_width) << truncate(list[i].get_first_name(), col_width)
				<< "| " << std::setw(col_width) << truncate(list[i].get_last_name(), col_width)
				<< "| " << std::setw(col_width) << truncate(list[i].get_nickname(), col_width)
				<< "\n";
		}

		int n;
		std::cout << "\nType index of the contact you want to see: ";
		std::cin >> n;
		std::cout << "\n";

		if (n > 8) {
			std::cout << "  Contact index out of range\n";
			return;
		}
		if (n> 0)
			print_contact(n - 1);
	}
};

#endif // PHONEBOOK_H
