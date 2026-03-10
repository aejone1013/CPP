/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:00:00 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/08 16:00:00 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <exception>

class PmergeMe {
private:
	std::vector<int> _vec;

	void parseInput(int argc, char** argv);

	void sortVector(std::vector<int>& v);
	void fjSortVec(std::vector<int>& v, int depth);

	void sortDeque(std::deque<int>& d);
	void fjSortDeq(std::deque<int>& d, int depth);

	static int jacobsthal(int n);

public:
	PmergeMe();
	PmergeMe(PmergeMe const & other);
	PmergeMe& operator=(PmergeMe const & other);
	~PmergeMe();

	void run(int argc, char** argv);
};

#endif
