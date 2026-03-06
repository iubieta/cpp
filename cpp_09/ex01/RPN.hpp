/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:47:27 by iubieta-          #+#    #+#             */
/*   Updated: 2026/03/07 00:18:31 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>


class RPN {
	private:
		std::string					_expr;
		static const std::string	VALID_TOKENS;

	public:
		RPN();
		RPN(const std::string &expr);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		float	evaluate();
};

#endif // !RPN_HPP
