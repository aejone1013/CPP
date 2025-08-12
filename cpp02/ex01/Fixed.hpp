/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 13:32:38 by jaoh              #+#    #+#             */
/*   Updated: 2025/08/12 14:48:49 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &src);
		Fixed(int const n);
		Fixed(float const f);
		~Fixed();

		Fixed	&operator=(Fixed const &src);
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

	private:
		int					_raw;
		static const int	_fractionalBits = 8;
};

std::ostream& operator<<( std::ostream& os, const Fixed& number );

#endif