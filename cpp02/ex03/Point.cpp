/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:00:01 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/29 17:34:17 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// 기본 생성자 - (0, 0)으로 초기화
Point::Point() : _x(0), _y(0) {
}

// float 매개변수 생성자
Point::Point(const float x, const float y) : _x(x), _y(y) {
}

// 복사 생성자
Point::Point(const Point& other) : _x(other._x), _y(other._y) {
}

// 대입 연산자 - const 멤버 변수 때문에 실제로는 대입 불가
Point& Point::operator=(const Point& other) {
    // const 멤버 변수는 대입할 수 없으므로 그대로 반환
    (void)other;  // 사용하지 않는 매개변수 경고 방지
    return *this;
}

// 소멸자
Point::~Point() {
}

// getter 함수들
Fixed Point::getX() const {
    return _x;
}

Fixed Point::getY() const {
    return _y;
}