/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:28:14 by iubieta-          #+#    #+#             */
/*   Updated: 2026/03/07 00:46:14 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <stdexcept>
#include <string>

// CHANONICAL FORM ============================================================

const std::string RPN::VALID_TOKENS = "1234567890 +-/*";

RPN::RPN() {};

RPN::RPN(const std::string &expr) : _expr(expr) {
	for (size_t i = 0; i < expr.size(); ++i) {
		if (VALID_TOKENS.find(expr[i]) == std::string::npos)
			throw std::runtime_error(std::string("ERROR: Invalid token found: ") += expr[i]);
	}
}

RPN::RPN(const RPN &other) {
	this->_expr = other._expr;
}

RPN& RPN::operator=(const RPN &other) {
	if (this != &other)
		this->_expr = other._expr;
	return *this;
}

RPN::~RPN() {}

float	RPN::evaluate() {
	std::stack<float>	op;
	float	aux, a, b;
	for (size_t i = 0; i < _expr.size(); ++i) {
		while (_expr[i] == ' ')
			i++;
		if (!_expr[i])
			break;
		if (std::isdigit(_expr[i]))
			op.push(_expr[i] - '0');
		else {
			while (op.size() > 1) {
				b = op.top();
				op.pop();
				a = op.top();
				op.pop();
				if (_expr[i] == '+') {
					aux = a + b;
				}
				else if (_expr[i] == '-') {
					aux = a - b;
				}
				else if (_expr[i] == '/') {
					aux = a / b;
				}
				else if (_expr[i] == '*') {
					aux = a * b;
				}
				op.push(aux);
			}
		}
	}
	return (op.top());
}
