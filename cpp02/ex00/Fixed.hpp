/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 23:05:36 by jaoh              #+#    #+#             */
/*   Updated: 2025/07/07 23:06:52 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;
		
	public:
		Fixed();
		Fixed(const Fixed &src);
		~Fixed();
		Fixed	&operator=(const Fixed &src);
		int		getRawBits() const;
		void	setRawBits(int const raw);

};

#endif