/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:00:00 by jaoh              #+#    #+#             */
/*   Updated: 2026/04/26 13:39:55 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cerrno>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const & other)
	: _vec(other._vec) {}

PmergeMe& PmergeMe::operator=(PmergeMe const & other) {
	if (this != &other) {
		_vec = other._vec;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		std::string arg(argv[i]);
		if (arg.empty())
			throw std::runtime_error("Error");
		for (size_t j = 0; j < arg.length(); j++) {
			if (j == 0 && arg[j] == '+')
				continue;
			if (arg[j] < '0' || arg[j] > '9')
				throw std::runtime_error("Error");
		}
		if (arg == "+")
			throw std::runtime_error("Error");
		errno = 0;
		long val = std::strtol(arg.c_str(), NULL, 10);
		if (errno == ERANGE || val < 0 || val > INT_MAX)
			throw std::runtime_error("Error");
		_vec.push_back(static_cast<int>(val));
	}
	if (_vec.empty())
		throw std::runtime_error("Error");
}

int PmergeMe::jacobsthal(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	int prev2 = 0;
	int prev1 = 1;
	for (int i = 2; i <= n; i++) {
		int cur = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = cur;
	}
	return prev1;
}

void PmergeMe::fjSortVec(std::vector<int>& v, int depth) {
	int groupSize = 1 << depth;

	int pairCount = static_cast<int>(v.size()) / (groupSize * 2);
	if (pairCount < 1)
		return;

	for (int i = 0; i < pairCount; i++) {
		int first = i * groupSize * 2;
		int second = first + groupSize;
		if (v[second] > v[first]) {
			for (int k = 0; k < groupSize; k++)
				std::swap(v[first + k], v[second + k]);
		}
	}

	fjSortVec(v, depth + 1);

	std::vector< std::vector<int> > mainGroups;
	std::vector< std::vector<int> > pendGroups;

	for (int i = 0; i < pairCount; i++) {
		int bigStart = i * groupSize * 2;
		int smallStart = bigStart + groupSize;

		std::vector<int> bigGroup(v.begin() + bigStart, v.begin() + bigStart + groupSize);
		std::vector<int> smallGroup(v.begin() + smallStart, v.begin() + smallStart + groupSize);

		mainGroups.push_back(bigGroup);
		pendGroups.push_back(smallGroup);
	}

	int pairedEnd = pairCount * groupSize * 2;
	int remaining = static_cast<int>(v.size()) - pairedEnd;

	std::vector< std::vector<int> > sorted;
	sorted.push_back(pendGroups[0]);
	for (size_t i = 0; i < mainGroups.size(); i++)
		sorted.push_back(mainGroups[i]);

	std::vector<bool> inserted(pendGroups.size(), false);
	inserted[0] = true;

	int jIdx = 2;
	size_t totalInserted = 1;
	while (totalInserted < pendGroups.size()) {
		int jVal = jacobsthal(jIdx);
		int insertIdx = jVal - 1;

		if (insertIdx >= static_cast<int>(pendGroups.size()))
			insertIdx = static_cast<int>(pendGroups.size()) - 1;

		for (int i = insertIdx; i >= 0 && totalInserted < pendGroups.size(); i--) {
			if (inserted[i])
				continue;
			inserted[i] = true;
			totalInserted++;

			int searchEnd = static_cast<int>(sorted.size());
			for (int s = 0; s < static_cast<int>(sorted.size()); s++) {
				if (sorted[s] == mainGroups[i]) {
					searchEnd = s;
					break;
				}
			}

			int lo = 0;
			int hi = searchEnd;
			int key = pendGroups[i][0];
			while (lo < hi) {
				int mid = lo + (hi - lo) / 2;
				if (sorted[mid][0] < key)
					lo = mid + 1;
				else
					hi = mid;
			}
			sorted.insert(sorted.begin() + lo, pendGroups[i]);
		}
		jIdx++;
	}

	if (remaining >= groupSize) {
		std::vector<int> oddGroup(v.begin() + pairedEnd, v.begin() + pairedEnd + groupSize);
		int lo = 0;
		int hi = static_cast<int>(sorted.size());
		int key = oddGroup[0];
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (sorted[mid][0] < key)
				lo = mid + 1;
			else
				hi = mid;
		}
		sorted.insert(sorted.begin() + lo, oddGroup);
	}

	int pos = 0;
	for (size_t i = 0; i < sorted.size(); i++) {
		for (size_t j = 0; j < sorted[i].size(); j++) {
			v[pos++] = sorted[i][j];
		}
	}
}

void PmergeMe::sortVector(std::vector<int>& v) {
	if (v.size() <= 1)
		return;
	fjSortVec(v, 0);
}

void PmergeMe::fjSortDeq(std::deque<int>& d, int depth) {
	int groupSize = 1 << depth;

	int pairCount = static_cast<int>(d.size()) / (groupSize * 2);
	if (pairCount < 1)
		return;

	for (int i = 0; i < pairCount; i++) {
		int first = i * groupSize * 2;
		int second = first + groupSize;
		if (d[second] > d[first]) {
			for (int k = 0; k < groupSize; k++)
				std::swap(d[first + k], d[second + k]);
		}
	}

	fjSortDeq(d, depth + 1);

	std::vector< std::deque<int> > mainGroups;
	std::vector< std::deque<int> > pendGroups;

	for (int i = 0; i < pairCount; i++) {
		int bigStart = i * groupSize * 2;
		int smallStart = bigStart + groupSize;

		std::deque<int> bigGroup(d.begin() + bigStart, d.begin() + bigStart + groupSize);
		std::deque<int> smallGroup(d.begin() + smallStart, d.begin() + smallStart + groupSize);

		mainGroups.push_back(bigGroup);
		pendGroups.push_back(smallGroup);
	}

	int pairedEnd = pairCount * groupSize * 2;
	int remaining = static_cast<int>(d.size()) - pairedEnd;

	std::vector< std::deque<int> > sorted;
	sorted.push_back(pendGroups[0]);
	for (size_t i = 0; i < mainGroups.size(); i++)
		sorted.push_back(mainGroups[i]);

	std::vector<bool> inserted(pendGroups.size(), false);
	inserted[0] = true;

	int jIdx = 2;
	size_t totalInserted = 1;
	while (totalInserted < pendGroups.size()) {
		int jVal = jacobsthal(jIdx);
		int insertIdx = jVal - 1;

		if (insertIdx >= static_cast<int>(pendGroups.size()))
			insertIdx = static_cast<int>(pendGroups.size()) - 1;

		for (int i = insertIdx; i >= 0 && totalInserted < pendGroups.size(); i--) {
			if (inserted[i])
				continue;
			inserted[i] = true;
			totalInserted++;

			int searchEnd = static_cast<int>(sorted.size());
			for (int s = 0; s < static_cast<int>(sorted.size()); s++) {
				if (sorted[s] == mainGroups[i]) {
					searchEnd = s;
					break;
				}
			}

			int lo = 0;
			int hi = searchEnd;
			int key = pendGroups[i][0];
			while (lo < hi) {
				int mid = lo + (hi - lo) / 2;
				if (sorted[mid][0] < key)
					lo = mid + 1;
				else
					hi = mid;
			}
			sorted.insert(sorted.begin() + lo, pendGroups[i]);
		}
		jIdx++;
	}

	if (remaining >= groupSize) {
		std::deque<int> oddGroup(d.begin() + pairedEnd, d.begin() + pairedEnd + groupSize);
		int lo = 0;
		int hi = static_cast<int>(sorted.size());
		int key = oddGroup[0];
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (sorted[mid][0] < key)
				lo = mid + 1;
			else
				hi = mid;
		}
		sorted.insert(sorted.begin() + lo, oddGroup);
	}

	int pos = 0;
	for (size_t i = 0; i < sorted.size(); i++) {
		for (size_t j = 0; j < sorted[i].size(); j++) {
			d[pos++] = sorted[i][j];
		}
	}
}

void PmergeMe::sortDeque(std::deque<int>& d) {
	if (d.size() <= 1)
		return;
	fjSortDeq(d, 0);
}

void PmergeMe::run(int argc, char** argv) {
    parseInput(argc, argv);
    std::cout << "Before:";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << " " << _vec[i];
    std::cout << std::endl;

    _vec.clear();
    clock_t startVec = clock();
    parseInput(argc, argv);
    std::vector<int> vecCopy(_vec);
    sortVector(vecCopy);
    clock_t endVec = clock();

    _vec.clear();
    clock_t startDeq = clock();
    parseInput(argc, argv);
    std::deque<int> deqCopy(_vec.begin(), _vec.end());
    sortDeque(deqCopy);
    clock_t endDeq = clock();

    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "After:";
    for (size_t i = 0; i < vecCopy.size(); i++)
        std::cout << " " << vecCopy[i];
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vecCopy.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deqCopy.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
