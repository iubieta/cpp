/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:45:08 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/05 14:49:29 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include "Animal.h"

class	Dog : public Animal {
	private:
		std::string	_type;	

	public:
		Dog();
		Dog(const std::string& type);
		Dog(const Dog& other);
		virtual ~Dog();

		Dog& operator=(const Dog& other);

		virtual void makeSound() const;
};

#endif
