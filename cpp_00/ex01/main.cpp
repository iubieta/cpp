/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:37:52 by iubieta-          #+#    #+#             */
/*   Updated: 2025/08/23 19:41:48 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 
// Write a program that works as a phonebook:
//
// Two classes:
//
//	- PhoneBook:
//		- Array of contacts
//		- Maximum of 8 contacts. Trying t add a 9th one, it will replace the oldest one.
//		- Dynamic allocation is forbidden.
//
//	- Contact:
//		- Fields:
//			- First name
//			- Last name
//			- Nickname
//			- Phone number
//			- Darkest secret
//		- A contact cant have empty fields
//
// Program commands:
//
//	- ADD:prompts input for contact info one field at a time.
//	- SEARCH:
//		- Display contact list:
//			- 4 columns (index, first name, last name, nickname)
//			- Each column 10 char wide, separated by '|'. 
//				If the text > 10 char it must be truncated and last char must be replaced by '.'
//		- Then prompt input for contact selection by index:
//			- Wrong (> 9): relevant behaviour
//			- Right (< 9): display contact info one field per line
//	- EXIT: program quits and contacts deleted.
//
//	* Discard wrong commands

#include "Phonebook.h"
#include <iostream>
#include <locale>

int main() {

	Phonebook	contactList;
	std::wstring	command;
	
    std::locale::global(std::locale(""));
    std::wcin.imbue(std::locale());
    std::wcout.imbue(std::locale());

	while (1) {
		std::cout 
			<< "\nPHONE-BO0K MENU:\n\n"
			<< "  - ADD (add new contact)\n"
			<< "  - SEARCH (search for a contact)\n"
			<< "  - EXIT\n"
			<< "\n> ";
		std::getline(std::wcin, command);
		if (command == L"ADD")
			contactList.addContact();
		else if (command == L"SEARCH")
			contactList.search_contact();
		else if (command == L"EXIT")
			break;
		if (std::wcin.eof())
		{
			std::wcout << "Goodbye!\n";
			break;
		}
	}

	return 0;
}
