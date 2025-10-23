/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:36:27 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/18 17:16:41 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {  // virtual inheritance (resolves diamond problem)
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
