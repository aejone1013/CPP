/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:49:23 by jaoh              #+#    #+#             */
/*   Updated: 2025/07/07 23:06:54 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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

// 원시값 반환 (변환하지 않음)
int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

// 원시값 설정
void Fixed::setRawBits(int const raw) {
    _value = raw;
}
