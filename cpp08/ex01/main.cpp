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
    std::cout << "=== Span Tests ===" << std::endl;
    
    // 주어진 테스트 코드
    std::cout << "\n--- Given Test Code ---" << std::endl;
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    // 예외 테스트
    std::cout << "\n--- Exception Tests ---" << std::endl;
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
    
    // 10,000개 숫자 테스트
    std::cout << "\n--- 10,000 Numbers Test ---" << std::endl;
    Span bigSpan(10000);
    std::srand(std::time(NULL));
    
    for (int i = 0; i < 10000; i++) {
        bigSpan.addNumber(std::rand());
    }
    
    std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
    
    // 범위 추가 테스트
    std::cout << "\n--- Range Addition Test ---" << std::endl;
    std::vector<int> vec;
    for (int i = 0; i < 100; i++) {
        vec.push_back(i * 2);
    }
    
    Span sp3(100);
    sp3.addRange(vec.begin(), vec.end());
    
    std::cout << "After adding 100 numbers via range:" << std::endl;
    std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
    
    // 음수 포함 테스트
    std::cout << "\n--- Negative Numbers Test ---" << std::endl;
    Span sp4(5);
    sp4.addNumber(-10);
    sp4.addNumber(-5);
    sp4.addNumber(0);
    sp4.addNumber(5);
    sp4.addNumber(10);
    
    std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp4.longestSpan() << std::endl;
    
    // 같은 숫자들 테스트
    std::cout << "\n--- Duplicate Numbers Test ---" << std::endl;
    Span sp5(5);
    sp5.addNumber(5);
    sp5.addNumber(5);
    sp5.addNumber(5);
    sp5.addNumber(10);
    sp5.addNumber(10);
    
    std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp5.longestSpan() << std::endl;
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    
    return 0;
}
