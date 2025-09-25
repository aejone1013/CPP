/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:06:00 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/29 18:17:18 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name);

int	main()
{
	int	n = 10;
	Zombie	*zombies = zombieHorde(n, "zombie");

	for (int i = 0; i < n; i++)
		zombies[i].announce();
	delete[] zombies;
}