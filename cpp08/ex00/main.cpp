/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:10:36 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/05 16:18:07 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>
#include "easyfind.hpp"

int main() {
    std::cout << "=== EasyFind Tests ===" << std::endl;
    
    // vector 테스트
    std::cout << "\n--- Vector Test ---" << std::endl;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found in vector: " << *it << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        easyfind(vec, 10);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // list 테스트
    std::cout << "\n--- List Test ---" << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    
    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found in list: " << *it << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    try {
        easyfind(lst, 50);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // deque 테스트
    std::cout << "\n--- Deque Test ---" << std::endl;
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    
    try {
        std::deque<int>::iterator it = easyfind(deq, 200);
        std::cout << "Found in deque: " << *it << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // 빈 컨테이너 테스트
    std::cout << "\n--- Empty Container Test ---" << std::endl;
    std::vector<int> emptyVec;
    
    try {
        easyfind(emptyVec, 1);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    // 첫 번째 발견 테스트 (중복 값)
    std::cout << "\n--- First Occurrence Test ---" << std::endl;
    std::vector<int> dupVec;
    dupVec.push_back(5);
    dupVec.push_back(10);
    dupVec.push_back(5);
    dupVec.push_back(20);
    
    try {
        std::vector<int>::iterator it = easyfind(dupVec, 5);
        std::cout << "Found first 5 at position: " 
                  << std::distance(dupVec.begin(), it) << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    
    return 0;
}
