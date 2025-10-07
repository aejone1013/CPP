/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:53:16 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/07 11:20:02 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Default constructor
Fixed::Fixed() : _value(0) {
}

// Copy constructor
Fixed::Fixed(const Fixed& other) : _value(other._value) {
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Destructor
Fixed::~Fixed() {
}

// Integer constructor
Fixed::Fixed(const int value) {
    _value = value << _fractionalBits;
}

// Float constructor
Fixed::Fixed(const float value) {
    _value = roundf(value * (1 << _fractionalBits));
}

// Get raw bits
int Fixed::getRawBits(void) const {
    return _value;
}

// Set raw bits
void Fixed::setRawBits(int const raw) {
    _value = raw;
}

// Convert fixed-point to float
float Fixed::toFloat(void) const {
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

// Convert fixed-point to integer
int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

// ==================== Comparison Operators ====================
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

// ==================== Arithmetic Operators ====================
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
    result._value = (_value * other._value) >> _fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    result._value = (_value << _fractionalBits) / other._value;
    return result;
}

// ==================== Increment/Decrement Operators ====================
// Pre-increment (++a)
Fixed& Fixed::operator++() {
    _value++;
    return *this;
}

// Post-increment (a++)
Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    _value++;
    return temp;
}

// Pre-decrement (--a)
Fixed& Fixed::operator--() {
    _value--;
    return *this;
}

// Post-decrement (a--)
Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    _value--;
    return temp;
}

// ==================== Static min/max Functions ====================
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

// Stream output operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}