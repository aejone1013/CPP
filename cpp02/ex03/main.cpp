/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:03:36 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/15 16:03:46 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void) {
    // 삼각형 정의: (0,0), (10,0), (5,10)
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);
    
    // 테스트 포인트들
    Point inside(5.0f, 5.0f);     // 내부
    Point outside(15.0f, 5.0f);   // 외부
    Point onEdge(5.0f, 0.0f);     // 변 위
    Point vertex(0.0f, 0.0f);     // 꼭짓점
    
    std::cout << "=== BSP (Binary Space Partitioning) Test ===" << std::endl;
    std::cout << "Triangle vertices: A(0,0), B(10,0), C(5,10)" << std::endl << std::endl;
    
    std::cout << "Point (5, 5) is inside triangle: " << 
                 (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
    std::cout << "Point (15, 5) is inside triangle: " << 
                 (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
    std::cout << "Point (5, 0) is inside triangle: " << 
                 (bsp(a, b, c, onEdge) ? "true" : "false") << std::endl;
    std::cout << "Point (0, 0) is inside triangle: " << 
                 (bsp(a, b, c, vertex) ? "true" : "false") << std::endl;
    
    // 추가 테스트들
    Point almostInside(2.5f, 2.5f);   // 내부 (경계 근처)
    Point farOutside(-5.0f, -5.0f);   // 완전히 외부
    
    std::cout << std::endl << "=== Additional Tests ===" << std::endl;
    std::cout << "Point (2.5, 2.5) is inside triangle: " << 
                 (bsp(a, b, c, almostInside) ? "true" : "false") << std::endl;
    std::cout << "Point (-5, -5) is inside triangle: " << 
                 (bsp(a, b, c, farOutside) ? "true" : "false") << std::endl;
    
    return 0;
}