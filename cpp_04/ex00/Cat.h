/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:53:46 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/05 14:35:17 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
# define CAT_H

#include "Animal.h"

class	Cat : public Animal {
	private:
		std::string	_type;	

	public:
		Cat();
		Cat(const std::string& type);
		Cat(const Cat& other);
		virtual ~Cat();

		Cat& operator=(const Cat& other);

		virtual void makeSound() const;
};

#endif
