/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 13:32:38 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/15 15:51:38 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

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
};

// 스트림 출력 연산자 (클래스 외부에서 정의)
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif