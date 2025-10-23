/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:38:26 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/17 23:38:36 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "=== FragTrap Inheritance Tests ===" << std::endl;
    
    // Constructor chaining test
    std::cout << "\n--- Constructor Chaining Test ---" << std::endl;
    FragTrap frag1("Destroyer");
    
    // FragTrap capability test
    std::cout << "\n--- FragTrap Status ---" << std::endl;
    std::cout << frag1.getName() << " - HP: " << frag1.getHitPoints() 
              << ", Energy: " << frag1.getEnergyPoints() 
              << ", Attack: " << frag1.getAttackDamage() << std::endl;
    
    // Attack tests (inherited from ClapTrap - not overridden)
    std::cout << "\n--- Attack Tests ---" << std::endl;
    frag1.attack("Enemy");
    frag1.attack("Target");
    
    // Damage and repair tests (inherited functions)
    std::cout << "\n--- Damage and Repair Tests ---" << std::endl;
    frag1.takeDamage(40);
    frag1.beRepaired(25);
    
    // FragTrap specific feature test
    std::cout << "\n--- Special Ability Test ---" << std::endl;
    frag1.highFivesGuys();
    
    // Copy tests
    std::cout << "\n--- Copy Tests ---" << std::endl;
    FragTrap frag2(frag1);
    FragTrap frag3;
    frag3 = frag1;
    
    // Compare all robot types
    std::cout << "\n--- All Robot Types Comparison ---" << std::endl;
    ClapTrap clap("BasicBot");
    ScavTrap scav("GuardBot");
    FragTrap frag("WarBot");
    
    std::cout << "ClapTrap stats: HP=" << clap.getHitPoints() 
              << ", Energy=" << clap.getEnergyPoints() 
              << ", Attack=" << clap.getAttackDamage() << std::endl;
    
    std::cout << "ScavTrap stats: HP=" << scav.getHitPoints() 
              << ", Energy=" << scav.getEnergyPoints() 
              << ", Attack=" << scav.getAttackDamage() << std::endl;
    
    std::cout << "FragTrap stats: HP=" << frag.getHitPoints() 
              << ", Energy=" << frag.getEnergyPoints() 
              << ", Attack=" << frag.getAttackDamage() << std::endl;
    
    // Attack style comparison
    std::cout << "\n--- Attack Style Comparison ---" << std::endl;
    clap.attack("Target");
    scav.attack("Target");   // Overridden message
    frag.attack("Target");   // ClapTrap message (not overridden)
    
    // Special abilities
    std::cout << "\n--- Special Abilities ---" << std::endl;
    scav.guardGate();
    frag.highFivesGuys();
    
    // Destructor chaining test
    std::cout << "\n--- Destructor Chaining Test ---" << std::endl;
    
    return 0;
}
