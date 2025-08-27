/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:57:27 by iubieta-          #+#    #+#             */
/*   Updated: 2025/07/30 13:11:25 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;
	
	std::cout 
		<< "Str: (" << &str << ") " << str << "\n"
		<< "Ptr: (" << &ptr << ") " << *ptr << "\n"
		<< "Ref: (" << &ref << ") " << ref << "\n";
}
