/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:58:48 by jaoh              #+#    #+#             */
/*   Updated: 2026/04/26 13:26:36 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <cstdlib>
#include <stack>
#include <cctype>
#include <sstream>
#include <climits>

RPN::RPN() {}

RPN::RPN(RPN const & other) { (void)other; }

RPN& RPN::operator=(RPN const & other) {
    (void)other;
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
    long result;

    switch (op) {
        case '+':
            result = static_cast<long>(a) + static_cast<long>(b);
            break;
        case '-':
            result = static_cast<long>(a) - static_cast<long>(b);
            break;
        case '*':
            result = static_cast<long>(a) * static_cast<long>(b);
            break;
        case '/':
            if (b == 0)
                throw std::runtime_error("Error");
            if (a == INT_MIN && b == -1)
                throw std::runtime_error("Error");
            return a / b;
        default:
            throw std::runtime_error("Error");
    }

    if (result < INT_MIN || result > INT_MAX)
        throw std::runtime_error("Error");
    return static_cast<int>(result);
}

int RPN::calculate(const std::string& expression) {
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token.length() != 1)
            throw std::runtime_error("Error");

        char c = token[0];
        if (isDigit(c)) {
            stack.push(c - '0');
        }
        else if (isOperator(c)) {
            if (stack.size() < 2)
                throw std::runtime_error("Error");
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            stack.push(performOperation(a, b, c));
        }
        else {
            throw std::runtime_error("Error");
        }
    }

    if (stack.size() != 1)
        throw std::runtime_error("Error");

    return stack.top();
}
