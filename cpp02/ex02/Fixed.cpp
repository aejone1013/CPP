/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:53:16 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/15 15:56:38 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// 기본 생성자 - 값을 0으로 초기화
Fixed::Fixed() : _value(0) {
}

// 복사 생성자
Fixed::Fixed(const Fixed& other) : _value(other._value) {
}

// 대입 연산자 오버로딩
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {  // 자기 자신과의 대입 방지
        this->_value = other._value;
    }
    return *this;
}

// 소멸자
Fixed::~Fixed() {
}

// int 생성자 - 정수를 고정소수점으로 변환
Fixed::Fixed(const int value) {
    // 정수를 고정소수점으로 변환: 왼쪽으로 _fractionalBits만큼 시프트
    _value = value << _fractionalBits;
}

// float 생성자 - 부동소수점을 고정소수점으로 변환
Fixed::Fixed(const float value) {
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

// ==================== 비교 연산자들 ====================
bool Fixed::operator>(const Fixed& other) const {
    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _value != other._value;
}

// ==================== 산술 연산자들 ====================
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result._value = _value + other._value;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result._value = _value - other._value;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    // 고정소수점 곱셈: 결과를 다시 _fractionalBits만큼 오른쪽으로 시프트
    result._value = (_value * other._value) >> _fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    // 고정소수점 나눗셈: _value를 먼저 왼쪽으로 시프트한 후 나눔
    result._value = (_value << _fractionalBits) / other._value;
    return result;
}

// ==================== 증감 연산자들 ====================
// 전위 증가 (++a) - 가장 작은 증가값 1/256 = 0.00390625
Fixed& Fixed::operator++() {
    _value++;
    return *this;
}

// 후위 증가 (a++) - 이전 값을 반환
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _value++;
    return temp;
}

// 전위 감소 (--a)
Fixed& Fixed::operator--() {
    _value--;
    return *this;
}

// 후위 감소 (a--)
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _value--;
    return temp;
}

// ==================== static min/max 함수들 ====================
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// 스트림 출력 연산자
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}