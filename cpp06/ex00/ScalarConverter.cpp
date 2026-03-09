/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:21:22 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/04 16:21:30 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// private 생성자들 (사용 불가)
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { 
    (void)other; 
    return *this; 
}
ScalarConverter::~ScalarConverter() {}

// char 타입인지 확인
bool ScalarConverter::isChar(const std::string& str) {
    return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

// int 타입인지 확인
bool ScalarConverter::isInt(const std::string& str) {
    if (str.empty()) return false;
    
    size_t start = 0;
    if (str[0] == '+' || str[0] == '-') start = 1;
    
    if (start >= str.length()) return false;
    
    for (size_t i = start; i < str.length(); i++) {
        if (!std::isdigit(str[i])) return false;
    }
    return true;
}

// 부호 뒤 숫자+소수점 하나를 검증하는 공통 헬퍼
bool ScalarConverter::isDecimalDigits(const std::string& s, size_t start, size_t end) {
    size_t dotCount = 0;
    if (start >= end) return false;
    for (size_t i = start; i < end; i++) {
        if (s[i] == '.') {
            if (++dotCount > 1) return false;
        } else if (!std::isdigit(s[i])) {
            return false;
        }
    }
    return dotCount == 1;
}

// 정수값 여부 확인 (NaN/Inf/범위 초과 안전하게 처리)
bool ScalarConverter::isWholeNumber(double value) {
    return !std::isnan(value) && !std::isinf(value) && std::fmod(value, 1.0) == 0.0;
}

// float 타입인지 확인
bool ScalarConverter::isFloat(const std::string& str) {
    if (str.length() < 2 || str[str.length() - 1] != 'f') return false;
    size_t start = (str[0] == '+' || str[0] == '-') ? 1 : 0;
    return isDecimalDigits(str, start, str.length() - 1);
}

// double 타입인지 확인
bool ScalarConverter::isDouble(const std::string& str) {
    if (str.empty()) return false;
    size_t start = (str[0] == '+' || str[0] == '-') ? 1 : 0;
    return isDecimalDigits(str, start, str.length());
}

// pseudo-literal인지 확인
bool ScalarConverter::isPseudoLiteral(const std::string& str) {
    return (str == "nan" || str == "nanf" || 
            str == "+inf" || str == "+inff" ||
            str == "-inf" || str == "-inff" ||
            str == "inf" || str == "inff");
}

// char에서 변환
void ScalarConverter::convertFromChar(char c) {
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

// int에서 변환
void ScalarConverter::convertFromInt(int n) {
    // char 변환
    if (n < 0 || n > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (n < 32 || n == 127) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
    }
    
    // int, float, double 변환
    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

// float에서 변환
void ScalarConverter::convertFromFloat(float f) {
    // char 변환
    if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (f < 32 || f >= 127) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    }
    
    // int 변환
    if (std::isnan(f) || std::isinf(f) || 
        f < std::numeric_limits<int>::min() || 
        f > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    }
    
    // float 출력
    std::cout << "float: " << f;
    if (isWholeNumber(f)) std::cout << ".0";
    std::cout << "f" << std::endl;

    // double 변환
    std::cout << "double: " << static_cast<double>(f);
    if (isWholeNumber(static_cast<double>(f))) std::cout << ".0";
    std::cout << std::endl;
}

// double에서 변환
void ScalarConverter::convertFromDouble(double d) {
    // char 변환
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (d < 32 || d >= 127) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    }
    
    // int 변환
    if (std::isnan(d) || std::isinf(d) || 
        d < std::numeric_limits<int>::min() || 
        d > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
    
    // float 변환
    std::cout << "float: " << static_cast<float>(d);
    if (isWholeNumber(static_cast<float>(d))) std::cout << ".0";
    std::cout << "f" << std::endl;

    // double 출력
    std::cout << "double: " << d;
    if (isWholeNumber(d)) std::cout << ".0";
    std::cout << std::endl;
}

// pseudo-literal 처리
void ScalarConverter::handlePseudoLiteral(const std::string& str) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (str == "nanf" || str == "nan") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (str == "+inff" || str == "+inf" || str == "inff" || str == "inf") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else if (str == "-inff" || str == "-inf") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

// 메인 변환 함수
void ScalarConverter::convert(const std::string& literal) {
    // pseudo-literal 체크
    if (isPseudoLiteral(literal)) {
        handlePseudoLiteral(literal);
        return;
    }
    
    // char 타입
    if (isChar(literal)) {
        convertFromChar(literal[1]);
        return;
    }
    
    // int 타입
    if (isInt(literal)) {
        long long temp = std::atoll(literal.c_str());
        if (temp < std::numeric_limits<int>::min() || 
            temp > std::numeric_limits<int>::max()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        convertFromInt(static_cast<int>(temp));
        return;
    }
    
    // float 타입
    if (isFloat(literal)) {
        float f = static_cast<float>(std::atof(literal.c_str()));
        convertFromFloat(f);
        return;
    }
    
    // double 타입
    if (isDouble(literal)) {
        double d = std::atof(literal.c_str());
        convertFromDouble(d);
        return;
    }
    
    // 인식할 수 없는 타입
    std::cout << "Error: Invalid literal" << std::endl;
}
