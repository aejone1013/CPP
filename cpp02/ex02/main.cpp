/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:53:46 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/15 15:56:42 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
    Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;

	std::cout << ++a << std::endl;
	std::cout << a << std::endl;

	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	std::cout << --a << std::endl;
	std::cout << a << std::endl;

	Fixed const c( Fixed( 5.6f ) / Fixed( 2 ) );
	std::cout << c << std::endl;

	Fixed const d( Fixed( 10 ) / Fixed( 2 ) );
	std::cout << d << std::endl;

	Fixed const e( Fixed( 15 ) / Fixed( 2 ) );
	std::cout << e << std::endl;
	return 0;
}