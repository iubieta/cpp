/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:29:22 by iubieta-          #+#    #+#             */
/*   Updated: 2026/02/17 19:25:30 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() {};
		MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}
		MutantStack& operator=(const MutantStack& other) {
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}
		~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }
};
