/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 18:44:41 by iubieta-          #+#    #+#             */
/*   Updated: 2025/08/26 19:33:28 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Phonebook.h"
#include "utils.h"

// Contact Class
// Constructor
Contact::Contact() {
	first_name = L"";
	last_name = L"";
	nickname = L"";
	number = L"";
	secret = L"";
};

// Sets
void Contact::set_first_name(std::wstring _first_name) {
	first_name = _first_name;
};
void Contact::set_last_name(std::wstring _last_name) {
	last_name = _last_name;
};
void Contact::set_nickname(std::wstring _nickname) {
	nickname = _nickname;
};
void Contact::set_number(std::wstring _number) {
	number = _number;
};
void Contact::set_secret(std::wstring _secret) {
	secret = _secret;
};

// Gets
std::wstring Contact::get_first_name() {
	return first_name;
};
std::wstring Contact::get_last_name() {
	return last_name;
};
std::wstring Contact::get_nickname() {
	return nickname;
};
std::wstring Contact::get_number() {
	return number;
};
std::wstring Contact::get_secret() {
	return secret;
};

// Phonebook Class
// Constructor
Phonebook::Phonebook() {
	size = 0;
};

void Phonebook::addContact() {

	int i;
	std::wstring	input;

	if (size == 8)
		i = 0;
	else {
		i = size;
		size++;
	}

	std::wcout << L"\n";
	
	input = askuser(L"  First name: ");
	if (input == L"")
		return;
	spaint(input);
	list[i].set_first_name(input);

	input = askuser(L"  Last name: ");
	if (input == L"")
		return;
	spaint(input);
	list[i].set_last_name(input);

	input = askuser(L"  Nickname: ");
	if (input == L"")
		return;
	spaint(input);
	list[i].set_nickname(input);

	while (1) {
		input = askuser(L"  Phone number: ");
		if (input == L"")
			return;
		if (input.find_first_not_of(L"-+0123456789") == std::string::npos)
			break;
		std::wcout << L"  Invalid input\n";
	}
	list[i].set_number(input);

	input = askuser(L"  Darkest secret: ");
	if (input == L"")
		return;
	spaint(input);
	list[i].set_secret(input);
}

void Phonebook::display_contact_list() {
	int col_width = 10;		
	std::wcout 
		<< std::left
		<< L"\n" << std::setw(col_width) << L"Index"
		<< L"| " << std::setw(col_width) << "First name"
		<< L"| " << std::setw(col_width) << "Last name"
		<< L"| " << std::setw(col_width) << "Nickname"
		<< L"\n";

	for (int i=0; i<size; i++) {
		std::wcout	
			<< std::setw(col_width) << i + 1
			<< L"| " << padright(list[i].get_first_name(), col_width)
			<< L"| " << padright(list[i].get_last_name(), col_width)
			<< L"| " << padright(list[i].get_nickname(), col_width)
			<< L"\n";
	}
	std::wcout << L"\n";
}

void Phonebook::print_contact(int i) {

	std::wcout << L"\n"
		<< L"  First name: " << list[i].get_first_name() << "\n"
		<< L"  Last name: " << list[i].get_last_name() << "\n"
		<< L"  Nickname: " << list[i].get_nickname() << "\n"
		<< L"  Phone number: " << list[i].get_number() << "\n"
		<< L"  Darkest secret: " << list[i].get_secret() << "\n";
}

void Phonebook::search_contact() {
	if (size < 1) {
		std::wcout << "  There are no contacts in the list.";
		std::wstring del;
		std::getline(std::wcin, del);
		return;
	}

	display_contact_list();

	std::wstring buff;
	int n;
	while (1) {
		buff = askuser(L"Type index of the contact you want to see: ");
		if (buff == L"")
			return;
		std::wistringstream iss(buff);
		if (iss >> n) {
			if (n < 1 || n > size)
				std::wcout << L" Index out of range.";
			else {
				print_contact(n - 1);
				break;
			}
		}
		std::wcout << L" Invalid input."; 
		std::wcout << L"\n";
	}
}
