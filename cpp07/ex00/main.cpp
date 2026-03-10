/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:45:49 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/05 15:45:55 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void) {
    std::cout << "=== Template Functions Tests ===" << std::endl;
    
    std::cout << "\n--- Given Test Code ---" << std::endl;
    int a = 2;
    int b = 3;
    
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
    
    std::string c = "chaine1";
    std::string d = "chaine2";
    
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
    
    std::cout << "\n--- Additional Tests ---" << std::endl;

    std::cout << "\nFloat test:" << std::endl;
    float f1 = 3.14f;
    float f2 = 2.71f;
    std::cout << "Before swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
    ::swap(f1, f2);
    std::cout << "After swap: f1 = " << f1 << ", f2 = " << f2 << std::endl;
    std::cout << "min(f1, f2) = " << ::min(f1, f2) << std::endl;
    std::cout << "max(f1, f2) = " << ::max(f1, f2) << std::endl;
    
    std::cout << "\nDouble test:" << std::endl;
    double d1 = 42.42;
    double d2 = 21.21;
    std::cout << "min(d1, d2) = " << ::min(d1, d2) << std::endl;
    std::cout << "max(d1, d2) = " << ::max(d1, d2) << std::endl;
    
    std::cout << "\nChar test:" << std::endl;
    char ch1 = 'a';
    char ch2 = 'z';
    std::cout << "Before swap: ch1 = " << ch1 << ", ch2 = " << ch2 << std::endl;
    ::swap(ch1, ch2);
    std::cout << "After swap: ch1 = " << ch1 << ", ch2 = " << ch2 << std::endl;
    std::cout << "min(ch1, ch2) = " << ::min(ch1, ch2) << std::endl;
    std::cout << "max(ch1, ch2) = " << ::max(ch1, ch2) << std::endl;
    
    std::cout << "\nEqual values test:" << std::endl;
    int e1 = 5;
    int e2 = 5;
    std::cout << "e1 = " << e1 << ", e2 = " << e2 << std::endl;
    std::cout << "min(e1, e2) returns second: " << &::min(e1, e2) 
              << " (e2 address: " << &e2 << ")" << std::endl;
    std::cout << "max(e1, e2) returns second: " << &::max(e1, e2) 
              << " (e2 address: " << &e2 << ")" << std::endl;
    
    std::cout << "\nReference return test:" << std::endl;
    int x = 10;
    int y = 20;
    int& minRef = const_cast<int&>(::min(x, y));
    minRef = 100;
    std::cout << "After modifying min reference: x = " << x << ", y = " << y << std::endl;
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    
    return 0;
}
