/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:37:08 by iubieta-          #+#    #+#             */
/*   Updated: 2025/02/23 18:39:09 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <bits/types/wint_t.h>
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

#endif // CONTACT_H
