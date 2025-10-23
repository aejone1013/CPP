/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:03:22 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/16 15:08:37 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    // Orthodox Canonical Form
    ScavTrap();                                    // Default constructor
    ScavTrap(const std::string& name);            // Parameterized constructor
    ScavTrap(const ScavTrap& other);              // Copy constructor
    ScavTrap& operator=(const ScavTrap& other);   // Assignment operator
    ~ScavTrap();                                  // Destructor

    // Overridden functions
    void attack(const std::string& target);       // Attack with a different message

    // ScavTrap specific features
    void guardGate();                             // Gatekeeper mode
};

#endif