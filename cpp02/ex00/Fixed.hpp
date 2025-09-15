/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 23:05:36 by jaoh              #+#    #+#             */
/*   Updated: 2025/07/07 23:06:52 by jaoh             ###   ########.fr       */
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

    // Exercise 00 required functions
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif