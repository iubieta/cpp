/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:49:39 by iubieta-          #+#    #+#             */
/*   Updated: 2025/08/26 19:24:14 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

std::wstring trim(const std::wstring& str) {
    size_t start = 0;
    while (start < str.size() && std::isspace(str[start])) {
        ++start;
    }

    size_t end = str.size();
    while (end > start && std::isspace(str[end - 1])) {
        --end;
    }

    return str.substr(start, end - start);
}

std::wstring truncate(const std::wstring &str, int width) {
	if (str.length() > (size_t)width)
		return (str.substr(0, width - 1) + L".");
	return str;
}

void spaint(std::wstring &str) {
	size_t pos;
	while ((pos = str.find(L"ñ")) != std::string::npos) {
		str.replace(pos, 1, L"n");
	}
	while ((pos = str.find(L"Ñ")) != std::string::npos) {
		str.replace(pos, 1, L"N");
	}
}

std::wstring padright(const std::wstring &str, int width) {
	int	diff = (size_t)width - str.length();
	if (diff > 0)
		return (str + std::wstring(diff, L' '));
	else
		return (truncate(str, width));
}

std::wstring askuser(const std::wstring msg) {
	std::wstring input = L"";

	while (input == L"")
	{
		std::wcout << msg;
		std::getline(std::wcin, input);
		input = trim(input);
		if (std::wcin.eof())
			return (L"");
		if (input == L"")
			std::wcout << L"  Empty field.\n";
	}
	return (input);
}
