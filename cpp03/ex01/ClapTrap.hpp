/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:05:47 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/16 15:08:31 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
protected:  // changed from private to protected (for inheritance)
    std::string _name;        // Name (passed to constructor)
    unsigned int _hitPoints;  // Hit points
    unsigned int _energyPoints; // Energy points
    unsigned int _attackDamage; // Attack damage

public:
    // Orthodox Canonical Form
    ClapTrap();                                    // Default constructor
    ClapTrap(const std::string& name);            // Parameterized constructor
    ClapTrap(const ClapTrap& other);              // Copy constructor
    ClapTrap& operator=(const ClapTrap& other);   // Assignment operator
    ~ClapTrap();                                  // Destructor

    // Member functions
    void attack(const std::string& target);       // Attack
    void takeDamage(unsigned int amount);         // Take damage
    void beRepaired(unsigned int amount);         // Repair

    // Getter functions
    std::string getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
};

#endif
