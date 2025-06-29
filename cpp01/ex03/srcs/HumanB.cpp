/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:59:21 by jaoh              #+#    #+#             */
/*   Updated: 2025/06/29 18:59:25 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*	Constructor	*/
HumanB::HumanB( std::string newName ) : _weapon(NULL)
{
	_name = newName;
}

/*	Desctructor	*/
HumanB::~HumanB(){}

void	HumanB::setWeapon(Weapon &newWeapon)
{
	_weapon = &newWeapon;
}

void	HumanB::attack()
{
	if (this->_weapon == NULL)
	{
		std::cout << _name << " attacks bare-handed, since he has no weapon!" << std::endl;
		return;
	}
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}
