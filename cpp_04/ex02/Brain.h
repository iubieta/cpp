/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:56:34 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/10 18:27:55 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ostream>
#include "colors.h"

#ifndef BRAIN_H
# define BRAIN_H

class Brain {
	private:
		std::string _ideas[100];
	
	public:
		Brain();
		Brain(const std::string& type);
		Brain(const Brain& other);
		~Brain();

		Brain& operator=(const Brain& other);

		void setIdea(int i, std::string idea);

		std::string getIdea(int i) const;
};
#endif