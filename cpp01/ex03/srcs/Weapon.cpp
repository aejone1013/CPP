/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:33:18 by mcombeau          #+#    #+#             */
/*   Updated: 2025/06/29 18:39:53 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/*	Constructor	*/
Weapon::Weapon() {}

Weapon::Weapon(std::string type) : _type(type) {}

/*	Desctructor	*/
Weapon::~Weapon(){}

std::string Weapon::getType() const
{
	return (this->_type);
}

void	Weapon::setType( std::string newType )
{
	this->_type = newType;
}
