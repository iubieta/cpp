/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:32:05 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/17 18:10:19 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_H
# define ROBOTOMY_REQUEST_FORM_H
#include <exception>
#include <iostream>
#include <iterator>
#include <string>
#include <ostream>
#include "AForm.h"
#include "colors.h"

class Bureaucrat;

class	RobotomyRequestForm : public AForm {
	private:
		std::string		_target;

		void			doAction() const;
		virtual void	print(std::ostream& out) const;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

		std::string		getTarget() const;
};

#endif
