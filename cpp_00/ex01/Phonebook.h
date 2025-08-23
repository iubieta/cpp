/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:39:41 by iubieta-          #+#    #+#             */
/*   Updated: 2025/08/23 19:36:20 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iomanip>
#include <ios>
#include <iostream>
#include <cctype>
#include <string>
#include <limits>

class Contact {

	private:

		std::wstring first_name;
		std::wstring last_name;
		std::wstring nickname;
		std::wstring number;
		std::wstring secret;

	public:

		Contact();

		void set_first_name(std::wstring _first_name);
		void set_last_name(std::wstring _last_name);
		void set_nickname(std::wstring _nickname);
		void set_number(std::wstring _number);
		void set_secret(std::wstring _secret);

		std::wstring get_first_name();
		std::wstring get_last_name();
		std::wstring get_nickname();
		std::wstring get_number();
};

class Phonebook {

	private:
		Contact list[8];
		int	size;
		
	public:
		Phonebook();
		void addContact();
		void print_contact(int i);
		void search_contact();
};

#endif 