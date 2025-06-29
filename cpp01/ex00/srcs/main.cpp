/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:39:19 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/29 15:49:45 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

int	main() {
	Zombie	*aZombie = newZombie("Heap");
	
	aZombie->announce();
	delete aZombie;

	randomChump("Stack");

	return (0);
}