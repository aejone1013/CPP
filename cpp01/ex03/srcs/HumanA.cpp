/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:33:11 by mcombeau          #+#    #+#             */
/*   Updated: 2025/06/29 18:47:18 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*	Constructor	*/
HumanA::HumanA(std::string newName, Weapon &newWeapon)  : _weapon(newWeapon)
{
	_name = newName;
}

/*	Desctructor	*/
HumanA::~HumanA() {}

void	HumanA::attack()
{
		std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;

}
