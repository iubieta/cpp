/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:53:46 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/13 19:35:50 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "Animal.h"
#include "Brain.h"

class	Cat : public Animal {
	private:
		std::string	_type;
		Brain	*_brain;

	public:
		Cat();
		Cat(const std::string& type);
		Cat(const Cat& other);
		~Cat();

		Cat& operator=(const Cat& other);

		void setIdea(int i, const std::string idea);

		std::string getIdea(int i) const;
		
		virtual void makeSound() const;
};

#endif
