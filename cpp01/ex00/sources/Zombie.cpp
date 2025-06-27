/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:47:38 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/27 15:02:33 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

/* constructors */
Zombie::Zombie( void )
{
	std::cout << "A zombie appeared!" << std::endl;
	return ;
}

Zombie::Zombie( std::string name ) : _name(name)
{
	std::cout << "--" << this->_getName() << " appeared--" << std::endl;
	return ;
}
/* destructor */
Zombie::~Zombie( void )
{
	std::cout << "--" << this->_getName() << " dead--" << std::endl;
	return ;
}

/* getter */
std::string Zombie::_getName( void ) const
{
	return ( this->_name );
}

/* public */
void	Zombie::announce( void )
{
	std::cout << this->_getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}