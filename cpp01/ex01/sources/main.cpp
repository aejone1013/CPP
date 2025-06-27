/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:06:00 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/27 15:08:34 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <string>
#include "Zombie.hpp"

#define LIMIT_MIN -50000
#define LIMIT_MAX 50000

Zombie *zombieHorde( int N, std::string name );

int	getNbZombies( void )
{
	int	nb;

	while (!( std::cin >> nb) || nb > LIMIT_MAX || nb < LIMIT_MIN ) {
		if (std::cin.eof())
			return ( 0 );
		std::cout << "Um... Let's be reasonable here. Why don't you try a number between " << LIMIT_MIN << " and " << LIMIT_MAX << "?" << std::endl
					<< "> ";
		std::cin.clear();
		std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
	}
	return (nb);
}

std::string	getHordeName( void )
{
	std::string	name;

	std::cin.ignore();
	std::cout << "Perfect! And what shall this horde be called?" << std::endl << "> ";
	std::getline(std::cin, name);
	if (std::cin.eof()) {
		return (std::string());
	}
	return ( name );
}

int	main( void )
{
	int			nb;
	std::string name;
	
	nb = getNbZombies();
	name = getHordeName();

	Zombie	*horde = zombieHorde(nb, name);
	if ( horde == NULL )
	{
		std::cout << "Your necromancy failed. These corpses will not rise." << std::endl;
		return ( 1 );
	}
	for ( int i = 0; i < nb; i++ )
		horde[i].announce();
	delete [] horde;
	return ( 0 );
}