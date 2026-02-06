/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 23:15:17 by iubieta-          #+#    #+#             */
/*   Updated: 2026/02/06 23:45:20 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BASE_H
# define BASE_H

class Base {
	public:
		virtual	~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif // !BASE_H
