/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:02:36 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/07 11:16:46 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Helper function to calculate the area of a triangle
// Using cross product for area calculation
static Fixed area(Point const& a, Point const& b, Point const& c) {
    Fixed result = (a.getX() * (b.getY() - c.getY()) +
                   b.getX() * (c.getY() - a.getY()) +
                   c.getX() * (a.getY() - b.getY()));
    
    return (result < 0) ? Fixed(0) - result : result;
}

// BSP (Binary Space Partitioning) function
// Check if a point is inside the triangle
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed originalArea = area(a, b, c);
    
    if (originalArea == Fixed(0))
        return false;
    
    Fixed area1 = area(point, b, c);
    Fixed area2 = area(a, point, c);
    Fixed area3 = area(a, b, point);
    
    if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
        return false;
    
    return (area1 + area2 + area3) == originalArea;
}