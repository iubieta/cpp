/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:57:54 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/13 20:12:05 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ostream>
#include "colors.h"

#ifndef ANIMAL_H
# define ANIMAL_H

class	Animal {
	private:
		std::string	_type;	

	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& other);
		virtual ~Animal();

		Animal& operator=(const Animal& other);

		std::string	getType() const;
		
		virtual void setIdea(int index, const std::string idea);
		virtual std::string getIdea(int index) const;
		virtual void makeSound() const;
};

#endif
