/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:53:46 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/17 16:36:38 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WCAT_H
# define WCAT_H

#include "WrongAnimal.h"

class	WrongCat : public WrongAnimal {

	public:
		WrongCat();
		WrongCat(const std::string& type);
		WrongCat(const WrongCat& other);
		virtual ~WrongCat();

		WrongCat& operator=(const WrongCat& other);

		virtual void makeSound() const;
};

#endif
