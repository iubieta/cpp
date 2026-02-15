/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:10:05 by iubieta-          #+#    #+#             */
/*   Updated: 2026/02/15 19:05:41 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iterator>
#include <vector>
class Span {
	private:
		unsigned int		_capacity;
		std::vector<int>	_data;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();

		template <typename InputIterator>
		void	addRange(InputIterator first, InputIterator last) {
			while (first != last) {
				this->addNumber(*first);
				++first;
			}
		}

		class FullException : public std::exception {
			public:
				const char * what() const throw() {
					return "Span is already full";
				}
		};
		
		class NoSpanException : public std::exception {
			public:
				const char * what() const throw() {
					return "Cannot calculate span with less than 2 elements";
				}
		};
};
