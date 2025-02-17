/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:37:52 by iubieta-          #+#    #+#             */
/*   Updated: 2025/02/17 20:42:21 by iubieta-         ###   ########.fr       */
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

#include <cstddef>
#include <iomanip>
#include <ios>
#include <iostream>
#include <cctype>
#include <string>

class Contact {

	private:

		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string number;
		std::string secret;

	public:

	Contact() {
		first_name = "";
		last_name = "";
		nickname = "";
		number = "";
	};

	Contact(std::string _first_name, std::string _last_name, std::string _nickname, std::string _number) {
		first_name = _first_name;
		last_name = _last_name;
		nickname = _nickname;
		number = _number;
	};

	void set_first_name(std::string _first_name) {
		first_name = _first_name;
	};
	void set_last_name(std::string _last_name) {
		last_name = _last_name;
	};
	void set_nickname(std::string _nickname) {
		nickname = _nickname;
	};
	void set_number(std::string _number) {
		number = _number;
	};

	std::string get_first_name() {
		return first_name;
	};
	std::string get_last_name() {
		return last_name;
	};
	std::string get_nickname() {
		return nickname;
	};
	std::string get_number() {
		return number;
	};
};


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
		
		std::cout << "First name: ";
		std::cin >> input;
		list[i].set_first_name(input);

		std::cout << "Last name: ";
		std::cin >> input;
		list[i].set_last_name(input);
		
		std::cout << "Nickname: ";
		std::cin >> input;
		list[i].set_nickname(input);

		std::cout << "Phone number: ";
		std::cin >> input;
		list[i].set_number(input);
	}

	void print_contact(int i) {
	
		std::cout 
			<< "First name: " << list[i].get_first_name() << "\n"
			<< "Last name: " << list[i].get_last_name() << "\n"
			<< "Nickname: " << list[i].get_nickname() << "\n"
			<< "Phone number: " << list[i].get_number() << "\n";
	}

	void display_contacts() {
	
		std::cout 
			<< std::left
			<< std::setw(10) << "Index"
			<< "| " << std::setw(10) << "First name"
			<< "| " << std::setw(10) << "Last name"
			<< "| " << std::setw(10) << "Nickname"
			<< "\n";
	
		for (int i=0; i<size; i++) {
			std::cout	
				<< std::setw(10) << i + 1
				<< "| " << std::setw(10) << list[i].get_first_name()
				<< "| " << std::setw(10) << list[i].get_last_name()
				<< "| " << std::setw(10) << list[i].get_nickname()
				<< "\n";
		}

		int n;
		std::cout << "Type index of the contact you want to see: ";
		std::cin >> n;

		if (n > 8) {
			std::cout << "Contact index out of range\n";
			return;
		}
		if (n> 0)
			print_contact(n - 1);
	}
};

int main() {
	PhoneBook contactList;
	contactList.display_contacts();
	contactList.addContact();
	contactList.display_contacts();
	return 0;
}
