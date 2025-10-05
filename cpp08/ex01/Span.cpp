/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:11:43 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/05 16:11:47 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

// 기본 생성자
Span::Span() : _maxSize(0) {}

// 매개변수 생성자
Span::Span(unsigned int N) : _maxSize(N) {
    _numbers.reserve(N);
}

// 복사 생성자
Span::Span(Span const & other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

// 대입 연산자
Span& Span::operator=(Span const & other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

// 소멸자
Span::~Span() {}

// 숫자 추가
void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw FullException();
    }
    _numbers.push_back(number);
}

// 최단 span 찾기
int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanException();
    }
    
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    int minSpan = std::numeric_limits<int>::max();
    
    for (size_t i = 1; i < sorted.size(); i++) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    
    return minSpan;
}

// 최장 span 찾기
int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanException();
    }
    
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    
    return max - min;
}

// 예외 구현
const char* Span::FullException::what() const throw() {
    return "Span is full, cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw() {
    return "Not enough numbers to calculate span";
}
