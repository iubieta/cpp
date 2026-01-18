/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:53:46 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/05 17:04:27 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H
#include <exception>
#include <iostream>
#include <iterator>
#include <string>
#include <ostream>
#include "colors.h"

class Bureaucrat;

class	Form {
	private:
		const std::string	_name;
		const int			_signGrade;	
		const int			_execGrade;	
		bool				_signed;
		
		int		checkGrade(int g);

	public:
		Form();
		Form(const std::string& n, const int sg, const int xg, const bool s);
		Form(const Form& other);
		~Form();

		Form&	operator=(const Form& other);

		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		int			getSigned() const;

		void	beSigned(Bureaucrat& bur);
	
		class FormIsAlreadySigned : public std::exception {
			public:
				const char* what() const throw() {
					return "Form is already signed";
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

std::ostream& operator<<(std::ostream& os, const Form&);

#endif
