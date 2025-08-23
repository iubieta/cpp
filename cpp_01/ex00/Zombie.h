/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 19:37:03 by iubieta-          #+#    #+#             */
/*   Updated: 2025/08/23 13:35:02 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H 

#include <iostream>
#include <string>

class Zombie {
	private:
		std::string	name;

	public:
		Zombie(std::string _name);
		
		void announce(void);

		~Zombie();
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
