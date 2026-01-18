/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 14:10:10 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/18 14:15:54 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

#include "AForm.h"
#include <string>

class	AForm;

class	Intern {
	private:
		int	_getFormType(const std::string name) const;

	public:
		Intern();
		Intern(const Intern& other);
		~Intern();

		Intern& operator=(const Intern& other);
		
		AForm*	makeForm(const std::string name, const std::string target) const;

	class UnknownFormType : public std::exception {
		public:
			const char* what() const throw() {
				return "Unknown type form";
			}
	};
};

#endif
