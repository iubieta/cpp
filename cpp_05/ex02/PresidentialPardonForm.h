/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 13:21:03 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/17 18:10:40 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_H
# define PRESIDENTIAL_PARDON_FORM_H
#include <exception>
#include <iostream>
#include <iterator>
#include <string>
#include <ostream>
#include "AForm.h"
#include "colors.h"

class Bureaucrat;

class	PresidentialPardonForm : public AForm {
	private:
		std::string		_target;

		void			doAction() const;
		virtual void	print(std::ostream& out) const;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

		std::string		getTarget() const;
};

#endif
