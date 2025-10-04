/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:00:45 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/04 17:04:05 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "functions.hpp"

int main() {
    std::cout << "=== Type Identification Tests ===" << std::endl;
    
    // 랜덤 생성 테스트
    std::cout << "\n--- Random Generation Test ---" << std::endl;
    for (int i = 0; i < 5; i++) {
        Base* random = generate();
        std::cout << "Identified by pointer: ";
        identify(random);
        std::cout << "Identified by reference: ";
        identify(*random);
        delete random;
        std::cout << std::endl;
    }
    
    // 각 타입별 직접 테스트
    std::cout << "\n--- Direct Type Test ---" << std::endl;
    
    std::cout << "Testing A:" << std::endl;
    A* a = new A();
    std::cout << "  By pointer: ";
    identify(a);
    std::cout << "  By reference: ";
    identify(*a);
    delete a;
    
    std::cout << "\nTesting B:" << std::endl;
    B* b = new B();
    std::cout << "  By pointer: ";
    identify(b);
    std::cout << "  By reference: ";
    identify(*b);
    delete b;
    
    std::cout << "\nTesting C:" << std::endl;
    C* c = new C();
    std::cout << "  By pointer: ";
    identify(c);
    std::cout << "  By reference: ";
    identify(*c);
    delete c;
    
    // Base 포인터로 저장된 타입 식별
    std::cout << "\n--- Base Pointer Identification ---" << std::endl;
    Base* baseA = new A();
    Base* baseB = new B();
    Base* baseC = new C();
    
    std::cout << "baseA: ";
    identify(baseA);
    std::cout << "baseB: ";
    identify(baseB);
    std::cout << "baseC: ";
    identify(baseC);
    
    delete baseA;
    delete baseB;
    delete baseC;
    
    // 배열 테스트
    std::cout << "\n--- Array Test ---" << std::endl;
    Base* array[6];
    array[0] = new A();
    array[1] = new B();
    array[2] = new C();
    array[3] = new A();
    array[4] = new B();
    array[5] = new C();
    
    for (int i = 0; i < 6; i++) {
        std::cout << "array[" << i << "]: ";
        identify(array[i]);
    }
    
    for (int i = 0; i < 6; i++) {
        delete array[i];
    }
    
    // NULL 포인터 테스트
    std::cout << "\n--- NULL Pointer Test ---" << std::endl;
    Base* nullPtr = NULL;
    identify(nullPtr);
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    
    return 0;
}
