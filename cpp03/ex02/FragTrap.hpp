/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:36:04 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/17 23:38:14 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
    // Orthodox Canonical Form
    FragTrap();                                    // Default constructor
    FragTrap(const std::string& name);            // Parameterized constructor
    FragTrap(const FragTrap& other);              // Copy constructor
    FragTrap& operator=(const FragTrap& other);   // Assignment operator
    ~FragTrap();                                  // Destructor

    // FragTrap specific features
    void highFivesGuys(void);                     // Request a high five
};

#endif