/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 19:16:13 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/29 19:16:21 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( void )
{
	Harl	grumblerHarl;

	grumblerHarl.complain("DEBUG");
	grumblerHarl.complain("ERROR");
	grumblerHarl.complain("INFO");
	grumblerHarl.complain("WARNING");
	grumblerHarl.complain("BAD_JOKES");
	return ( 0 );
}