/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 17:14:27 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/18 17:18:10 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string _name;  // DiamondTrap's own name (same variable name as ClapTrap::_name)

public:
    // Orthodox Canonical Form
    DiamondTrap();                                      // Default constructor
    DiamondTrap(const std::string& name);              // Parameterized constructor
    DiamondTrap(const DiamondTrap& other);             // Copy constructor
    DiamondTrap& operator=(const DiamondTrap& other);  // Assignment operator
    ~DiamondTrap();                                    // Destructor

    // DiamondTrap specific features
    void whoAmI();                                     // Print names

    // Use 'using' declaration to specify which attack to use (ScavTrap's attack)
    using ScavTrap::attack;
};

#endif
