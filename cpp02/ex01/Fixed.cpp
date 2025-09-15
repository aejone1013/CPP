/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:53:54 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/15 15:51:39 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// 기본 생성자 - 값을 0으로 초기화
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// 복사 생성자
Fixed::Fixed(const Fixed& other) : _value(other._value) {
    std::cout << "Copy constructor called" << std::endl;
}

// 대입 연산자 오버로딩
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {  // 자기 자신과의 대입 방지
        this->_value = other._value;
    }
    return *this;
}

// 소멸자
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// int 생성자 - 정수를 고정소수점으로 변환
Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    // 정수를 고정소수점으로 변환: 왼쪽으로 _fractionalBits만큼 시프트
    _value = value << _fractionalBits;
}

// float 생성자 - 부동소수점을 고정소수점으로 변환
Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    // 부동소수점을 고정소수점으로 변환: 2^8 = 256을 곱하고 반올림
    _value = roundf(value * (1 << _fractionalBits));
}

// 원시값 반환 (변환하지 않음)
int Fixed::getRawBits(void) const {
    return _value;
}

// 원시값 설정
void Fixed::setRawBits(int const raw) {
    _value = raw;
}

// 고정소수점을 부동소수점으로 변환
float Fixed::toFloat(void) const {
    // 2^8로 나누어서 부동소수점으로 변환
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

// 고정소수점을 정수로 변환
int Fixed::toInt(void) const {
    // 오른쪽으로 _fractionalBits만큼 시프트하여 정수 부분만 추출
    return _value >> _fractionalBits;
}

// 스트림 출력 연산자
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}