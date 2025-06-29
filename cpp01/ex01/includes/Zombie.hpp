/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:05:49 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/29 18:14:35 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
#include <string>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie();
		Zombie( std::string name );
		~Zombie();
		void	announce(void);
		void	setName( std::string name );
};

#endif