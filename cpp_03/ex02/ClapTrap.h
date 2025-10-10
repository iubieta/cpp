/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 11:57:54 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/10 19:05:27 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ostream>

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class	ClapTrap {
	protected:
		std::string	_name;	
		int			_hitPts;	
		int			_energyPts;	
		int			_attackDmg;

	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		ClapTrap(const std::string& name, int hp, int energy, int dmg);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();

		ClapTrap& operator=(const ClapTrap& other);

		std::string	getName() const;
		int			getHitPts() const;
		int			getEnergyPts() const;
		int			getAttackDmg() const;
		
		void	attack(const std::string& target);
		void	takeDamage(const unsigned int amount);
		void	beReapaired(const unsigned int amount);

		void	status() const;
};

#endif // !CLAPTRAP_H
