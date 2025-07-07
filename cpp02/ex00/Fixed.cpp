/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:49:23 by jaoh              #+#    #+#             */
/*   Updated: 2025/07/07 23:06:54 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructor	*/
Fixed::Fixed() : _value(0)
{
	std::cout << "Fixed constructor" << std::endl;
}

/* Copy constructor */
Fixed::Fixed(const Fixed &src) : _value(src._value)
{
	std::cout << "Copy constructor" << std::endl;

}

/* Desctructor */
Fixed::~Fixed(){}

Fixed &Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_value = src._value;
	return *this;
}

int	Fixed::getRawBits() const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
