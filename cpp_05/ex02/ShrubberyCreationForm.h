/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:29:33 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/17 18:10:42 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SHRUBBERY_CREATION_FORM_H
# define SHRUBBERY_CREATION_FORM_H
#include <exception>
#include <iostream>
#include <iterator>
#include <string>
#include <ostream>
#include "AForm.h"
#include "colors.h"

class Bureaucrat;

class	ShrubberyCreationForm : public AForm {
	private:
		std::string		_target;

		void			doAction() const;
		virtual void	print(std::ostream& out) const;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

		std::string		getTarget() const;
};

#endif
