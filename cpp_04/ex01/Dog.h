/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:45:08 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/13 19:36:10 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include "Animal.h"
#include "Brain.h"

class	Dog : public Animal {
	private:
		std::string	_type;	
		Brain	*_brain;

	public:
		Dog();
		Dog(const std::string& type);
		Dog(const Dog& other);
		~Dog();

		Dog& operator=(const Dog& other);

		void setIdea(int i, const std::string idea);

		std::string getIdea(int i) const;

		void makeSound() const;
};

#endif
