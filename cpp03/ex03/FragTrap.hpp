/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:36:04 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/18 17:17:25 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {  // virtual inheritance (resolves diamond problem)
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