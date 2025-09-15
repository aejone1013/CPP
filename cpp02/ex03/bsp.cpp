/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:02:36 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/15 16:03:47 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// 삼각형의 넓이를 계산하는 헬퍼 함수
// 외적(cross product)을 이용한 넓이 계산
static Fixed area(Point const& a, Point const& b, Point const& c) {
    Fixed result = (a.getX() * (b.getY() - c.getY()) +
                   b.getX() * (c.getY() - a.getY()) +
                   c.getX() * (a.getY() - b.getY()));
    
    // 절댓값 반환 (음수일 수 있으므로)
    return (result < 0) ? Fixed(0) - result : result;
}

// BSP (Binary Space Partitioning) 함수
// 점이 삼각형 내부에 있는지 확인
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // 원본 삼각형의 넓이
    Fixed originalArea = area(a, b, c);
    
    // 만약 원본 삼각형의 넓이가 0이면 (일직선상에 있음) false 반환
    if (originalArea == Fixed(0))
        return false;
    
    // 점 P와 삼각형의 각 변으로 만들어지는 세 개의 작은 삼각형들의 넓이
    Fixed area1 = area(point, b, c);  // P-B-C 삼각형
    Fixed area2 = area(a, point, c);  // A-P-C 삼각형  
    Fixed area3 = area(a, b, point);  // A-B-P 삼각형
    
    // 만약 어느 하나라도 넓이가 0이면 점이 변 위에 있음
    if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
        return false;
    
    // 세 작은 삼각형의 넓이의 합이 원본 삼각형의 넓이와 같으면 내부에 있음
    return (area1 + area2 + area3) == originalArea;
}