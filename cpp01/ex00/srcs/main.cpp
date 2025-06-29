/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:39:19 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/29 17:49:57 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name) ;

int	main() {
	Zombie	*a = newZombie("Hel");
	
	a->announce();
	delete a;
	randomChump("Lo");
	Zombie	*b = newZombie("World");
	b->announce();
	delete b;
}