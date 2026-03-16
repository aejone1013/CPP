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

namespace {
    void printImpossible() {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { 
    (void)other; 
    return *this; 
}
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& str) {
    if (str.length() == 1 &&
        !std::isdigit(static_cast<unsigned char>(str[0]))) {
        return true;
    }
    return (str.length() == 3 && str[0] == '\'' && str[2] == '\'');
}

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

bool ScalarConverter::isWholeNumber(double value) {
    return !std::isnan(value) && !std::isinf(value) && std::fmod(value, 1.0) == 0.0;
}

bool ScalarConverter::isFloat(const std::string& str) {
    if (str.length() < 2 || str[str.length() - 1] != 'f') return false;
    size_t start = (str[0] == '+' || str[0] == '-') ? 1 : 0;
    return isDecimalDigits(str, start, str.length() - 1);
}

bool ScalarConverter::isDouble(const std::string& str) {
    if (str.empty()) return false;
    size_t start = (str[0] == '+' || str[0] == '-') ? 1 : 0;
    return isDecimalDigits(str, start, str.length());
}

bool ScalarConverter::isPseudoLiteral(const std::string& str) {
    return (str == "nan" || str == "nanf" || 
            str == "+inf" || str == "+inff" ||
            str == "-inf" || str == "-inff" ||
            str == "inf" || str == "inff");
}

void ScalarConverter::convertFromChar(char c) {
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(int n) {
    if (n < 0 || n > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (n < 32 || n == 127) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
    }
    
    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(float f) {
    if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (f < 32 || f >= 127) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    }
    
    if (std::isnan(f) || std::isinf(f) || 
        f < std::numeric_limits<int>::min() || 
        f > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    }
    
    std::cout << "float: " << f;
    if (isWholeNumber(f)) std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << static_cast<double>(f);
    if (isWholeNumber(static_cast<double>(f))) std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convertFromDouble(double d) {
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127) {
        std::cout << "char: impossible" << std::endl;
    } else if (d < 32 || d >= 127) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    }
    
    if (std::isnan(d) || std::isinf(d) || 
        d < std::numeric_limits<int>::min() || 
        d > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
    
    std::cout << "float: " << static_cast<float>(d);
    if (isWholeNumber(static_cast<float>(d))) std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << d;
    if (isWholeNumber(d)) std::cout << ".0";
    std::cout << std::endl;
}

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

void ScalarConverter::convert(const std::string& literal) {
    if (isPseudoLiteral(literal)) {
        handlePseudoLiteral(literal);
        return;
    }
    
    if (isChar(literal)) {
        if (literal.length() == 1) {
            convertFromChar(literal[0]);
        } else {
            convertFromChar(literal[1]);
        }
        return;
    }
    
    if (isInt(literal)) {
        long long temp = std::atoll(literal.c_str());
        if (temp < std::numeric_limits<int>::min() || 
            temp > std::numeric_limits<int>::max()) {
            errno = 0;
            double d = std::strtod(literal.c_str(), NULL);
            if (errno == ERANGE) {
                printImpossible();
                return;
            }
            convertFromDouble(d);
            return;
        }
        convertFromInt(static_cast<int>(temp));
        return;
    }
    
    if (isFloat(literal)) {
        float f = static_cast<float>(std::atof(literal.c_str()));
        convertFromFloat(f);
        return;
    }
    
    if (isDouble(literal)) {
        double d = std::atof(literal.c_str());
        convertFromDouble(d);
        return;
    }
    
    printImpossible();
}
