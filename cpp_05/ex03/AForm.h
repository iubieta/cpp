/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:53:46 by iubieta-          #+#    #+#             */
/*   Updated: 2026/01/17 18:13:26 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
# define AFORM_H
#include <exception>
#include <iostream>
#include <string>
#include "colors.h"

class Bureaucrat;

class	AForm {
	protected:
		const std::string	_name;
		const int			_signGrade;	
		const int			_execGrade;	
		bool				_signed;

		virtual void		doAction() const = 0;

	public:
		AForm();
		AForm(const std::string& n, const int sg, const int xg, bool s);
		AForm(const AForm& other);
		~AForm();

		AForm&			operator=(const AForm& other);

		std::string		getName() const;
		int				getSignGrade() const;
		int				getExecGrade() const;
		int				getSigned() const;

		int				checkGrade(int g, int max, int min) const;
		void			beSigned(const Bureaucrat& signer);
		void			execute(const Bureaucrat& executor) const;

		virtual	void	print(std::ostream& out) const;

	
	class FormIsAlreadySigned : public std::exception {
		public:
			const char* what() const throw() {
				return "Form is already signed";
			}
	};

	class NotSignedForm : public std::exception {
		public:
			const char* what() const throw() {
				return "AForm is not signed";
			}
	};
	
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade too high";
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade too low";
			}
	};
};

std::ostream& operator<<(std::ostream& os, const AForm&);

#endif
