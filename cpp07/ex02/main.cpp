/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:52:01 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/05 15:52:17 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**) {
    std::cout << "=== Array Template Class Tests ===" << std::endl;
    
    // 주어진 테스트 코드
    std::cout << "\n--- Given Test Code ---" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::srand(std::time(NULL));
    
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
    // SCOPE - 복사 테스트
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    
    // 값 비교 테스트
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "✓ All values matched!" << std::endl;
    
    // 음수 인덱스 테스트
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    // 범위 초과 인덱스 테스트
    try {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    // 값 변경
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = std::rand();
    }
    
    delete[] mirror;
    
    // 추가 테스트들
    std::cout << "\n--- Additional Tests ---" << std::endl;
    
    // 빈 배열 테스트
    std::cout << "\nEmpty array test:" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;
    
    try {
        emptyArray[0] = 42;
    }
    catch(const std::exception& e) {
        std::cout << "Empty array access exception: " << e.what() << std::endl;
    }
    
    // 작은 배열 테스트
    std::cout << "\nSmall array test:" << std::endl;
    Array<int> smallArray(5);
    std::cout << "Small array size: " << smallArray.size() << std::endl;
    
    for (unsigned int i = 0; i < smallArray.size(); i++) {
        smallArray[i] = i * 10;
    }
    
    std::cout << "Small array values: ";
    for (unsigned int i = 0; i < smallArray.size(); i++) {
        std::cout << smallArray[i] << " ";
    }
    std::cout << std::endl;
    
    // 깊은 복사 테스트
    std::cout << "\nDeep copy test:" << std::endl;
    Array<int> original(3);
    original[0] = 1;
    original[1] = 2;
    original[2] = 3;
    
    Array<int> copy = original;
    copy[0] = 100;
    
    std::cout << "Original[0]: " << original[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;
    
    if (original[0] != copy[0]) {
        std::cout << "✓ Deep copy successful (different values)" << std::endl;
    }
    
    // string 배열 테스트
    std::cout << "\nString array test:" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "!";
    
    std::cout << "String array: ";
    for (unsigned int i = 0; i < strArray.size(); i++) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;
    
    // float 배열 테스트
    std::cout << "\nFloat array test:" << std::endl;
    Array<float> floatArray(4);
    floatArray[0] = 3.14f;
    floatArray[1] = 2.71f;
    floatArray[2] = 1.41f;
    floatArray[3] = 1.73f;
    
    std::cout << "Float array: ";
    for (unsigned int i = 0; i < floatArray.size(); i++) {
        std::cout << floatArray[i] << " ";
    }
    std::cout << std::endl;
    
    // const 배열 테스트
    std::cout << "\nConst array test:" << std::endl;
    Array<int> const constArray(3);
    std::cout << "Const array size: " << constArray.size() << std::endl;
    std::cout << "Const array[0]: " << constArray[0] << std::endl;
    
    // 대입 연산자 테스트
    std::cout << "\nAssignment operator test:" << std::endl;
    Array<int> arr1(3);
    arr1[0] = 10;
    arr1[1] = 20;
    arr1[2] = 30;
    
    Array<int> arr2(5);
    arr2 = arr1;
    
    std::cout << "arr2 size after assignment: " << arr2.size() << std::endl;
    std::cout << "arr2 values: ";
    for (unsigned int i = 0; i < arr2.size(); i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    
    return 0;
}
