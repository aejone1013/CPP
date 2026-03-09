/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:11:57 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/05 16:12:01 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try {
        sp.addNumber(42);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    Span sp2(1);
    sp2.addNumber(5);
    try {
        sp2.shortestSpan();
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    Span bigSpan(10000);
    std::srand(std::time(NULL));
    for (int i = 0; i < 10000; i++)
        bigSpan.addNumber(std::rand());
    std::cout << "Shortest: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest: " << bigSpan.longestSpan() << std::endl;

    std::vector<int> vec;
    for (int i = 0; i < 100; i++)
        vec.push_back(i * 2);
    Span sp3(100);
    sp3.addRange(vec.begin(), vec.end());
    std::cout << "Shortest: " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp3.longestSpan() << std::endl;

    return 0;
}
