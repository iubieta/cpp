/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 13:53:46 by iubieta-          #+#    #+#             */
/*   Updated: 2025/10/05 17:04:27 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <exception>
#include <iostream>
#include <iterator>
#include <string>
#include <ostream>
#include "colors.h"


class	Bureaucrat {
	private:
		const std::string	_name;	
		int			_grade;	

		int			checkGrade(int grade);

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

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		std::string getName() const;
		int			getGrade() const;

		void		upgrade();
		void 		downgrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat&);


#endif
