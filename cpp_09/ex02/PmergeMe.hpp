/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iubieta- <iubieta@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 19:34:17 by iubieta-          #+#    #+#             */
/*   Updated: 2026/03/08 23:46:32 by iubieta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <list>
#include <string>
#include <vector>

class PmergeMe {
	private:
		std::string			_input;
		std::vector<int>	_vec;
		std::list<int>		_ls;

	public:
		PmergeMe();
		PmergeMe(const std::string &input);
		PmergeMe(PmergeMe &other);
		PmergeMe& operator=(PmergeMe &other);
		~PmergeMe();

		std::string			getInput() const;
		std::vector<int>	sortVector() const;
		std::list<int>		sortList() const;
};

#endif  
