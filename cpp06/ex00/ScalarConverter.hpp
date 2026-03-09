/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:20:53 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/04 16:23:05 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>
#include <cstdlib>

class ScalarConverter {
private:
    // 인스턴스화 방지
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    // 타입 감지 헬퍼
    static bool isChar(const std::string& str);
    static bool isInt(const std::string& str);
    static bool isFloat(const std::string& str);
    static bool isDouble(const std::string& str);
    static bool isPseudoLiteral(const std::string& str);
    static bool isDecimalDigits(const std::string& s, size_t start, size_t end);
    static bool isWholeNumber(double value);

    // 변환 헬퍼
    static void convertFromChar(char c);
    static void convertFromInt(int n);
    static void convertFromFloat(float f);
    static void convertFromDouble(double d);
    static void handlePseudoLiteral(const std::string& str);

public:
    // 유일한 public 메서드
    static void convert(const std::string& literal);
};

#endif
