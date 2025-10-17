/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:57:54 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/17 16:36:24 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ostream>

#ifndef WANIMAL_H
# define WANIMAL_H

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class	WrongAnimal {
	protected:
		std::string	_type;	

	public:
		WrongAnimal();
		WrongAnimal(const std::string& type);
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& other);

		std::string	getType() const;
	
		void makeSound() const;
};

#endif
