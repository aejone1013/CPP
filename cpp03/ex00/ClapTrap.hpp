/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 17:16:39 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/15 17:17:01 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
private:
    std::string _name;          // 이름
    unsigned int _hitPoints;    // 체력 (10)
    unsigned int _energyPoints; // 에너지 (10)
    unsigned int _attackDamage; // 공격력 (0)

public:
    // Orthodox Canonical Form
    ClapTrap();                                   
    ClapTrap(const std::string& name);            
    ClapTrap(const ClapTrap& other);              
    ClapTrap& operator=(const ClapTrap& other);   
    ~ClapTrap();                                  

    // 동작 함수
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // Getter
    std::string getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
};

#endif
