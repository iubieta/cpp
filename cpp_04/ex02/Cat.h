/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:53:46 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/17 16:51:09 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "Animal.h"
#include "Brain.h"

class	Cat : public Animal {
	private:
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
