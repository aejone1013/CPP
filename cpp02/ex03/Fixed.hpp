/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:57:58 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/15 15:59:05 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>

class Fixed {
private:
    int _value;                           // 고정소수점 값을 저장
    static const int _fractionalBits = 8; // 소수 부분을 위한 비트 수 (항상 8)

public:
    // Orthodox Canonical Form (Coplien Form)
    Fixed();                              // 기본 생성자
    Fixed(const Fixed& other);           // 복사 생성자
    Fixed& operator=(const Fixed& other); // 대입 연산자 오버로딩
    ~Fixed();                            // 소멸자

    // Exercise 00 functions
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Exercise 01 additions
    Fixed(const int value);               // int 생성자
    Fixed(const float value);             // float 생성자
    float toFloat(void) const;            // float로 변환
    int toInt(void) const;                // int로 변환

    // Exercise 02 additions - 비교 연산자들
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // 산술 연산자들
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // 증가/감소 연산자들 (전위, 후위)
    Fixed& operator++();      // 전위 증가 (++a)
    Fixed operator++(int);    // 후위 증가 (a++)
    Fixed& operator--();      // 전위 감소 (--a)
    Fixed operator--(int);    // 후위 감소 (a--)

    // static min/max 함수들
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

// 스트림 출력 연산자 (클래스 외부에서 정의)
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif