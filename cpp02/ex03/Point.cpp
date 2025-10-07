/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:00:01 by jaoh              #+#    #+#             */
/*   Updated: 2025/10/07 11:13:59 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor
Point::Point() : _x(0), _y(0) {
}

// Float parameter constructor
Point::Point(const float x, const float y) : _x(x), _y(y) {
}

// Copy constructor
Point::Point(const Point& other) : _x(other._x), _y(other._y) {
}

// Assignment operator
Point& Point::operator=(const Point& other) {
    (void)other;
    return *this;
}

// Destructor
Point::~Point() {
}

// ==== Getter functions ====
Fixed Point::getX() const {
    return _x;
}

Fixed Point::getY() const {
    return _y;
}