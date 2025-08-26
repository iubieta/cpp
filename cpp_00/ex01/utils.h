/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:50:32 by iubieta-          #+#    #+#             */
/*   Updated: 2025/08/26 18:53:30 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include <iomanip>
#include <ios>
#include <iostream>
#include <cctype>
#include <string>
#include <limits>
#include <sstream>

std::wstring truncate(const std::wstring &str, int width);
void spaint(std::wstring &str);
std::wstring padright(const std::wstring &str, int width);
std::wstring askuser(const std::wstring msg);

#endif 
