/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:14:39 by jaoh              #+#    #+#             */
/*   Updated: 2025/05/18 17:34:00 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	std::string const msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (ac == 1)
		std::cout << msg;
	for (int i = 1; av[i]; i++) {
		for (int j = 0; av[i][j]; j++)
		std::cout << (char)std::toupper(av[i][j]);
	}
	std::cout << std::endl;
	return (0);
}
