/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:57:54 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/17 16:13:22 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ostream>

#ifndef ANIMAL_H
# define ANIMAL_H

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class	Animal {
	protected:
		std::string	_type;	

	public:
		Animal();
		//Animal(const std::string& type);
		Animal(const Animal& other);
		virtual ~Animal();

		Animal& operator=(const Animal& other);

		std::string	getType() const;
	
		virtual void makeSound() const;
};

#endif
