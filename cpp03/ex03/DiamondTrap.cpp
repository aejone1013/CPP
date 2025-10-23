/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:14:41 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/18 17:18:25 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Default constructor
DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap(), _name("Default") {
    // Set attributes according to DiamondTrap specification
    _hitPoints = FragTrap::_hitPoints;        // Hit points from FragTrap (100)
    _energyPoints = ScavTrap::_energyPoints;  // Energy points from ScavTrap (50)
    _attackDamage = FragTrap::_attackDamage;  // Attack damage from FragTrap (30)
    
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

// Parameterized constructor
DiamondTrap::DiamondTrap(const std::string& name) 
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
    // Set attributes according to DiamondTrap specification
    _hitPoints = FragTrap::_hitPoints;        // Hit points from FragTrap (100)
    _energyPoints = ScavTrap::_energyPoints;  // Energy points from ScavTrap (50)
    _attackDamage = FragTrap::_attackDamage;  // Attack damage from FragTrap (30)
    
    std::cout << "DiamondTrap " << _name << " constructor called" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other) 
    : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

// Assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        _name = other._name;
    }
    return *this;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

// whoAmI function - prints DiamondTrap's name and its ClapTrap name
void DiamondTrap::whoAmI() {
    std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
