/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:53:54 by jaoh              #+#    #+#             */
/*   Updated: 2025/08/12 14:48:40 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* Constructor */
Fixed::Fixed() : _raw(0)
{
	std::cerr << "Fixed constructor" << std::endl;
}

/* Copy Constructor */
Fixed::Fixed(Fixed const &src)  : _raw(src._raw)
{
	std::cerr << "Copy constructor" << std::endl;
}

/* Integer constructor */
Fixed::Fixed( int const n ) : _raw(n << _fractionalBits)
{
	std::cerr << "Int constructor" << std::endl;
}

/* Float constructor */
Fixed::Fixed(float const f) : _raw(roundf(f * (1 << _fractionalBits)))
{
	std::cerr << "Float constructor" << std::endl;
}

/* Desctructor */
Fixed::~Fixed()
{
	std::cerr << "Fixed destructor" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &src)
{
	std::cerr << "Copy assignment operator called." << std::endl;
	if (this != &src)
		this->_raw = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	std::cerr << "getRawBits member function called." << std::endl;
	return (this->_raw);
}

void	Fixed::setRawBits(int const raw)
{
	std::cerr << "setRawBits member funtion called." << std::endl;
	this->_raw = raw;
	return ;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/
int		Fixed::toInt() const
{
	return (this->_raw >> Fixed::_fractionalBits);	
}

float	Fixed::toFloat() const
{
	return ((float)this->_raw / (1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream& os, const Fixed &number)
{
	os << number.toFloat();
	return (os);
}