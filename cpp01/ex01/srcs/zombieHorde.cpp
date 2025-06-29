/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:11:12 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/29 18:14:38 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{
	if (n <= 0)
	{
		std::cerr << "Please provide a correct size!" << std::endl;
		return (NULL);
	}
	Zombie	*zombies = new Zombie[n];

	for (int i = 0; i < n; i++)
		zombies[i].setName(name);

	return (zombies);
}