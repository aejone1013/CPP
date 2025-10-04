/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:03:01 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/04 17:04:06 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// 랜덤하게 A, B, C 중 하나를 생성
Base* generate(void) {
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }
    
    int random = std::rand() % 3;
    
    switch (random) {
        case 0:
            std::cout << "[Generated type A]" << std::endl;
            return new A();
        case 1:
            std::cout << "[Generated type B]" << std::endl;
            return new B();
        case 2:
            std::cout << "[Generated type C]" << std::endl;
            return new C();
        default:
            return NULL;
    }
}

// 포인터로 타입 식별 (dynamic_cast 사용)
void identify(Base* p) {
    if (p == NULL) {
        std::cout << "Null pointer" << std::endl;
        return;
    }
    
    // dynamic_cast로 타입 확인
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

// 레퍼런스로 타입 식별 (포인터 사용 금지 - 예외 처리 사용)
void identify(Base& p) {
    // dynamic_cast를 레퍼런스에 사용하면
    // 실패시 예외(std::bad_cast)가 발생함
    
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception&) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception&) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception&) {}
    
    std::cout << "Unknown type" << std::endl;
}
