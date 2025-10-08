/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:58:48 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/08 16:05:18 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(RPN const & other) : _stack(other._stack) {}

RPN& RPN::operator=(RPN const & other) {
    if (this != &other) {
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool RPN::isDigit(char c) const {
    return c >= '0' && c <= '9';
}

int RPN::performOperation(int a, int b, char op) const {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                throw std::runtime_error("Error: division by zero");
            }
            return a / b;
        default:
            throw std::runtime_error("Error: invalid operator");
    }
}

int RPN::calculate(const std::string& expression) {
    // 스택 초기화: 새 계산마다 내부 스택을 비움
    while (!_stack.empty()) {
        _stack.pop();
    }
    
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        // RPN 규칙: 토큰은 한 글자(숫자 0-9 또는 연산자)여야 함
        if (token.length() != 1) {
            throw std::runtime_error("Error");
        }
        
        char c = token[0];
        
        // 괄호는 허용하지 않음
        if (c == '(' || c == ')') {
            throw std::runtime_error("Error");
        }
        
        // 숫자인 경우(0~9)
        if (isDigit(c)) {
            _stack.push(c - '0');
        }
        // 연산자인 경우: 스택에서 두 피연산자(a, b)를 꺼내 순서 주의
        else if (isOperator(c)) {
            if (_stack.size() < 2) {
                throw std::runtime_error("Error");
            }
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            int result = performOperation(a, b, c);
            _stack.push(result);
        }
        else {
            throw std::runtime_error("Error");
        }
    }
    
    // 최종적으로 스택에 정확히 하나의 값만 남아야 유효한 RPN 표현식
    if (_stack.size() != 1) {
        throw std::runtime_error("Error");
    }
    
    return _stack.top();
}
