/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:03:36 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/07 11:16:57 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main(void) {
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);
    
    Point inside(5.0f, 5.0f);
    Point outside(15.0f, 5.0f);
    Point onEdge(5.0f, 0.0f);
    Point vertex(0.0f, 0.0f);
    
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
    
    Point almostInside(2.5f, 2.5f);
    Point farOutside(-5.0f, -5.0f);
    
    std::cout << std::endl << "=== Additional Tests ===" << std::endl;
    std::cout << "Point (2.5, 2.5) is inside triangle: " << 
                 (bsp(a, b, c, almostInside) ? "true" : "false") << std::endl;
    std::cout << "Point (-5, -5) is inside triangle: " << 
                 (bsp(a, b, c, farOutside) ? "true" : "false") << std::endl;
    
    return 0;
}