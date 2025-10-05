/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:50:01 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/05 15:50:16 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// 테스트용 함수들

// 출력 함수 (템플릿)
template <typename T>
void printElement(T const & element) {
    std::cout << element << " ";
}

// 값 증가 함수
void incrementInt(int& n) {
    n++;
}

// 값 두 배로 증가
void doubleValue(int& n) {
    n *= 2;
}

// 문자열 대문자 변환
void toUpper(std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
        str[i] = std::toupper(str[i]);
    }
}

// float 제곱
void squareFloat(float& f) {
    f = f * f;
}

// const 요소 출력용
void printConstInt(int const & n) {
    std::cout << "[" << n << "]";
}

int main(void) {
    std::cout << "=== Iter Template Function Tests ===" << std::endl;
    
    // int 배열 테스트
    std::cout << "\n--- Int Array Test ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Original: ";
    iter(intArray, intSize, printElement<int>);
    std::cout << std::endl;
    
    iter(intArray, intSize, incrementInt);
    std::cout << "After increment: ";
    iter(intArray, intSize, printElement<int>);
    std::cout << std::endl;
    
    iter(intArray, intSize, doubleValue);
    std::cout << "After double: ";
    iter(intArray, intSize, printElement<int>);
    std::cout << std::endl;
    
    // string 배열 테스트
    std::cout << "\n--- String Array Test ---" << std::endl;
    std::string strArray[] = {"hello", "world", "test", "cpp"};
    size_t strSize = sizeof(strArray) / sizeof(strArray[0]);
    
    std::cout << "Original: ";
    iter(strArray, strSize, printElement<std::string>);
    std::cout << std::endl;
    
    iter(strArray, strSize, toUpper);
    std::cout << "After toUpper: ";
    iter(strArray, strSize, printElement<std::string>);
    std::cout << std::endl;
    
    // float 배열 테스트
    std::cout << "\n--- Float Array Test ---" << std::endl;
    float floatArray[] = {1.5f, 2.5f, 3.5f, 4.5f};
    size_t floatSize = sizeof(floatArray) / sizeof(floatArray[0]);
    
    std::cout << "Original: ";
    iter(floatArray, floatSize, printElement<float>);
    std::cout << std::endl;
    
    iter(floatArray, floatSize, squareFloat);
    std::cout << "After square: ";
    iter(floatArray, floatSize, printElement<float>);
    std::cout << std::endl;
    
    // char 배열 테스트
    std::cout << "\n--- Char Array Test ---" << std::endl;
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charSize = sizeof(charArray) / sizeof(charArray[0]);
    
    std::cout << "Chars: ";
    iter(charArray, charSize, printElement<char>);
    std::cout << std::endl;
    
    // const 배열 테스트
    std::cout << "\n--- Const Array Test ---" << std::endl;
    int const constArray[] = {10, 20, 30, 40, 50};
    size_t constSize = sizeof(constArray) / sizeof(constArray[0]);
    
    std::cout << "Const array: ";
    iter(constArray, constSize, printConstInt);
    std::cout << std::endl;
    
    // 빈 배열 테스트
    std::cout << "\n--- Empty Array Test ---" << std::endl;
    int emptyArray[0];
    iter(emptyArray, 0, printElement<int>);
    std::cout << "(empty array - no output)" << std::endl;
    
    // NULL 포인터 테스트
    std::cout << "\n--- NULL Pointer Test ---" << std::endl;
    int* nullPtr = NULL;
    iter(nullPtr, 5, printElement<int>);
    std::cout << "(NULL pointer - no output)" << std::endl;
    
    std::cout << "\n=== End of Tests ===" << std::endl;
    
    return 0;
}
