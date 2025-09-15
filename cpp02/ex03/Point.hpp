/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:00:26 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/15 16:01:45 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    const Fixed _x;  // x 좌표 (상수)
    const Fixed _y;  // y 좌표 (상수)

public:
    // Orthodox Canonical Form
    Point();                              // 기본 생성자 (0, 0)
    Point(const float x, const float y);  // float 매개변수 생성자
    Point(const Point& other);           // 복사 생성자
    Point& operator=(const Point& other); // 대입 연산자
    ~Point();                            // 소멸자

    // getter 함수들
    Fixed getX() const;
    Fixed getY() const;
};

// BSP 함수 선언
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif