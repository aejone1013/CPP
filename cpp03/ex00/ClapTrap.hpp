/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:16:39 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/16 15:13:25 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
private:
    std::string _name;        // Name (passed to constructor)
    unsigned int _hitPoints;  // Hit points (10)
    unsigned int _energyPoints; // Energy points (10)
    unsigned int _attackDamage; // Attack damage (0)

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

    // Getter functions (for testing)
    std::string getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
};

#endif