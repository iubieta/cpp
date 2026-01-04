/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:45:08 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/17 16:51:15 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include "Animal.h"
#include "Brain.h"

class	Dog : public Animal {
	private:
		Brain	*_brain;

	public:
		Dog();
		Dog(const std::string& type);
		Dog(const Dog& other);
		~Dog();

		Dog& operator=(const Dog& other);

		void setIdea(int i, const std::string idea);

		std::string getIdea(int i) const;

		virtual void makeSound() const;
};

#endif
