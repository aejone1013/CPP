/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaoh <jaoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 23:38:26 by jaoh              #+#    #+#             */
/*   Updated: 2025/09/18 17:18:43 by jaoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "=== DiamondTrap Multiple Inheritance Tests ===" << std::endl;
    
    // DiamondTrap constructor chaining test
    std::cout << "\n--- DiamondTrap Constructor Chaining Test ---" << std::endl;
    DiamondTrap diamond("Hybrid");
    
    // DiamondTrap status check
    std::cout << "\n--- DiamondTrap Status ---" << std::endl;
    std::cout << diamond.getName() << " - HP: " << diamond.getHitPoints() 
              << ", Energy: " << diamond.getEnergyPoints() 
              << ", Attack: " << diamond.getAttackDamage() << std::endl;
    
    // whoAmI test
    std::cout << "\n--- whoAmI Test ---" << std::endl;
    diamond.whoAmI();
    
    // Attack test (uses ScavTrap's attack)
    std::cout << "\n--- Attack Test (ScavTrap's attack) ---" << std::endl;
    diamond.attack("Target");
    
    // Test special abilities from each parent class
    std::cout << "\n--- Special Abilities from Parents ---" << std::endl;
    diamond.guardGate();      // from ScavTrap
    diamond.highFivesGuys();  // from FragTrap
    
    // Basic ClapTrap functions
    std::cout << "\n--- Basic ClapTrap Functions ---" << std::endl;
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    
    // Copy tests
    std::cout << "\n--- Copy Tests ---" << std::endl;
    DiamondTrap diamond2(diamond);
    DiamondTrap diamond3;
    diamond3 = diamond;
    
    diamond2.whoAmI();
    diamond3.whoAmI();
    
    // Compare all robot types
    std::cout << "\n--- All Robot Types Comparison ---" << std::endl;
    ClapTrap clap("BasicBot");
    ScavTrap scav("GuardBot");
    FragTrap frag("WarBot");
    DiamondTrap dia("HybridBot");
    
    std::cout << "ClapTrap stats: HP=" << clap.getHitPoints() 
              << ", Energy=" << clap.getEnergyPoints() 
              << ", Attack=" << clap.getAttackDamage() << std::endl;
    
    std::cout << "ScavTrap stats: HP=" << scav.getHitPoints() 
              << ", Energy=" << scav.getEnergyPoints() 
              << ", Attack=" << scav.getAttackDamage() << std::endl;
    
    std::cout << "FragTrap stats: HP=" << frag.getHitPoints() 
              << ", Energy=" << frag.getEnergyPoints() 
              << ", Attack=" << frag.getAttackDamage() << std::endl;
    
    std::cout << "DiamondTrap stats: HP=" << dia.getHitPoints() 
              << ", Energy=" << dia.getEnergyPoints() 
              << ", Attack=" << dia.getAttackDamage() << std::endl;
    
    // Attack style comparison
    std::cout << "\n--- Attack Style Comparison ---" << std::endl;
    clap.attack("Enemy");
    scav.attack("Enemy");
    frag.attack("Enemy");
    dia.attack("Enemy");     // Uses ScavTrap's attack
    
    // All special abilities
    std::cout << "\n--- All Special Abilities ---" << std::endl;
    scav.guardGate();
    frag.highFivesGuys();
    dia.guardGate();
    dia.highFivesGuys();
    dia.whoAmI();
    
    // Destructor chaining test
    std::cout << "\n--- Destructor Chaining Test ---" << std::endl;
    
    return 0;
}
